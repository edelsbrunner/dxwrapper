/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

// Default
#include "Settings\Settings.h"
#include "Dllmain\Dllmain.h"
#include "Hook\inithook.h"
#include "Utils\Utils.h"
#include "wrapper.h"
// Wrappers
#include "bcrypt.h"
#include "cryptsp.h"
#include "D3d8to9\d3d8.h"
#include "d3d8.h"
#include "d3d9.h"
#include "dsound.h"
#include "ddraw.h"
#include "dinput.h"
#include "dplayx.h"
#include "dxgi.h"
#include "winmm.h"
#include "winspool.h"
// Libraries
#include "d3dx9.h"
#include "dwmapi.h"
#include "uxtheme.h"

namespace Wrapper
{
	struct custom_dll
	{
		bool Flag = false;
		HMODULE dll = nullptr;
	};

	custom_dll custom[256];
	custom_dll dllhandle[dtypeArraySize];

	void LoadCustomDll();
	void FreeCustomLibrary();
}

// Wrapper classes
VISIT_WRAPPERS(ADD_NAMESPACE_CLASS)

// Proc functions
VISIT_WRAPPERS(CREATE_ALL_PROC_STUB)

// Default function
HRESULT WINAPI ReturnProc()
{
	// Do nothing
	return E_NOTIMPL;
}

// Load real dll file that is being wrapped
HMODULE Wrapper::LoadDll(DWORD dlltype)
{
	// Check for valid dlltype
	if (dlltype == 0 || dlltype >= dtypeArraySize)
	{
		return nullptr;
	}

	// Check if dll is already loaded
	if (dllhandle[dlltype].Flag)
	{
		return dllhandle[dlltype].dll;
	}
	dllhandle[dlltype].Flag = true;

	// Load dll from ini, if DllPath is not '0'
	if (Config.szDllPath[0] != '\0' && Config.RealWrapperMode == dlltype)
	{
		LOG << "Loading " << Config.szDllPath << " library";
		dllhandle[dlltype].dll = LoadLibrary(Config.szDllPath);
		if (!dllhandle[dlltype].dll)
		{
			LOG << "Cannot load " << Config.szDllPath << " library";
		}
	}

	// Load current dll
	if (!dllhandle[dlltype].dll && Config.RealWrapperMode != dlltype)
	{
		LOG << "Loading " << dtypename[dlltype] << " library";
		dllhandle[dlltype].dll = LoadLibrary(dtypename[dlltype]);
		if (!dllhandle[dlltype].dll)
		{
			LOG << "Cannot load " << dtypename[dlltype] << " library";
		}
	}

	// Load default system dll
	if (!dllhandle[dlltype].dll)
	{
		char path[MAX_PATH];
		GetSystemDirectory(path, MAX_PATH);
		strcat_s(path, MAX_PATH, "\\");
		strcat_s(path, MAX_PATH, dtypename[dlltype]);
		LOG << "Loading " << path << " library";
		dllhandle[dlltype].dll = LoadLibrary(path);
	}

	// Cannot load dll
	if (!dllhandle[dlltype].dll)
	{
		LOG << "Cannot load " << dtypename[dlltype] << " library";
		if (Config.WrapperMode != 0 && Config.WrapperMode != 255)
		{
			ExitProcess(0);
		}
	}

	// Return dll handle
	return dllhandle[dlltype].dll;
}

// Load custom dll files
void Wrapper::LoadCustomDll()
{
	for (UINT x = 1; x <= Config.CustomDllCount; ++x)
	{
		if (Config.szCustomDllPath[x] != '\0')
		{
			LOG << "Loading custom " << Config.szCustomDllPath[x] << " library";
			// Load dll from ini
			custom[x].dll = LoadLibrary(Config.szCustomDllPath[x]);
			// Load from system
			if (!custom[x].dll)
			{
				char path[MAX_PATH];
				GetSystemDirectory(path, MAX_PATH);
				strcat_s(path, MAX_PATH, "\\");
				strcat_s(path, MAX_PATH, Config.szCustomDllPath[x]);
				custom[x].dll = LoadLibrary(path);
			}
			// Cannot load dll
			if (!custom[x].dll)
			{
				LOG << "Cannot load custom " << Config.szCustomDllPath[x] << " library";
			}
			else {
				custom[x].Flag = true;
			}
		}
	}
}

// Unload custom dll files
void Wrapper::FreeCustomLibrary()
{
	for (UINT x = 1; x <= Config.CustomDllCount; ++x)
	{
		// If dll was loaded
		if (custom[x].Flag)
		{
			// Unload dll
			FreeLibrary(custom[x].dll);
		}
	}
}

// Load wrapper dll files
void Wrapper::DllAttach()
{
	VISIT_WRAPPERS(LOAD_WRAPPER);
	if (Config.WrapperMode != 0)
	{
		if (Config.WrapperMode != dtype.d3d8 && Config.D3d8to9)
		{
			d3d8::module.Load();
		}
		if (Config.WrapperMode != dtype.dsound && Config.DSoundCtrl)
		{
			dsound::module.Load();
		}
		if (Config.WrapperMode != dtype.ddraw && Config.DDrawCompat)
		{
			ddraw::module.Load();
		}
	}
	if (Config.CustomDllCount > 0)
	{
		LoadCustomDll();
	}
}

// Unload all dll files loaded by the wrapper
void Wrapper::DllDetach()
{
	// Unload custom libraries
	FreeCustomLibrary();

	// Unload wrapper libraries
	for (UINT x = 1; x < dtypeArraySize; ++x)
	{
		// If dll was loaded
		if (dllhandle[x].dll)
		{
			// Unload dll
			FreeLibrary(dllhandle[x].dll);
		}
	}

	// Unload dynmaic libraries
	UnLoadd3dx9();
	UnLoaddwmapi();
	UnLoadUxtheme();
}
