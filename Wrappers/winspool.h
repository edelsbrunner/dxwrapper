#pragma once

#define VISIT_WINSPOOL_PROCS(visit) \
	visit(ADVANCEDSETUPDIALOG) \
	visit(AdvancedSetupDialog) \
	visit(ConvertAnsiDevModeToUnicodeDevmode) \
	visit(ConvertUnicodeDevModeToAnsiDevmode) \
	visit(DEVICEMODE) \
	visit(DeviceMode) \
	visit(DocumentEvent) \
	visit(PerfClose) \
	visit(PerfCollect) \
	visit(PerfOpen) \
	visit(QueryColorProfile) \
	visit(QueryRemoteFonts) \
	visit(QuerySpoolMode) \
	visit(SpoolerDevQueryPrintW) \
	visit(StartDocDlgW) \
	visit(AbortPrinter) \
	visit(AddFormA) \
	visit(AddFormW) \
	visit(AddJobA) \
	visit(AddJobW) \
	visit(AddMonitorA) \
	visit(AddMonitorW) \
	visit(AddPortA) \
	visit(AddPortExA) \
	visit(AddPortExW) \
	visit(AddPortW) \
	visit(AddPrintProcessorA) \
	visit(AddPrintProcessorW) \
	visit(AddPrintProvidorA) \
	visit(AddPrintProvidorW) \
	visit(AddPrinterA) \
	visit(AddPrinterConnection2A) \
	visit(AddPrinterConnection2W) \
	visit(AddPrinterConnectionA) \
	visit(AddPrinterConnectionW) \
	visit(AddPrinterDriverA) \
	visit(AddPrinterDriverExA) \
	visit(AddPrinterDriverExW) \
	visit(AddPrinterDriverW) \
	visit(AddPrinterW) \
	visit(AdvancedDocumentPropertiesA) \
	visit(AdvancedDocumentPropertiesW) \
	visit(ClosePrinter) \
	visit(CloseSpoolFileHandle) \
	visit(CommitSpoolData) \
	visit(ConfigurePortA) \
	visit(ConfigurePortW) \
	visit(ConnectToPrinterDlg) \
	visit(CorePrinterDriverInstalledA) \
	visit(CorePrinterDriverInstalledW) \
	visit(CreatePrintAsyncNotifyChannel) \
	visit(CreatePrinterIC) \
	visit(DEVICECAPABILITIES) \
	visit(DeleteFormA) \
	visit(DeleteFormW) \
	visit(DeleteJobNamedProperty) \
	visit(DeleteMonitorA) \
	visit(DeleteMonitorW) \
	visit(DeletePortA) \
	visit(DeletePortW) \
	visit(DeletePrintProcessorA) \
	visit(DeletePrintProcessorW) \
	visit(DeletePrintProvidorA) \
	visit(DeletePrintProvidorW) \
	visit(DeletePrinter) \
	visit(DeletePrinterConnectionA) \
	visit(DeletePrinterConnectionW) \
	visit(DeletePrinterDataA) \
	visit(DeletePrinterDataExA) \
	visit(DeletePrinterDataExW) \
	visit(DeletePrinterDataW) \
	visit(DeletePrinterDriverA) \
	visit(DeletePrinterDriverExA) \
	visit(DeletePrinterDriverExW) \
	visit(DeletePrinterDriverPackageA) \
	visit(DeletePrinterDriverPackageW) \
	visit(DeletePrinterDriverW) \
	visit(DeletePrinterIC) \
	visit(DeletePrinterKeyA) \
	visit(DeletePrinterKeyW) \
	visit(DevQueryPrint) \
	visit(DevQueryPrintEx) \
	visit(DeviceCapabilities) \
	visit(DeviceCapabilitiesA) \
	visit(DeviceCapabilitiesW) \
	visit(DevicePropertySheets) \
	visit(DocumentPropertiesA) \
	visit(DocumentPropertiesW) \
	visit(DocumentPropertySheets) \
	visit(EXTDEVICEMODE) \
	visit(EndDocPrinter) \
	visit(EndPagePrinter) \
	visit(EnumFormsA) \
	visit(EnumFormsW) \
	visit(EnumJobNamedProperties) \
	visit(EnumJobsA) \
	visit(EnumJobsW) \
	visit(EnumMonitorsA) \
	visit(EnumMonitorsW) \
	visit(EnumPortsA) \
	visit(GetDefaultPrinterA) \
	visit(SetDefaultPrinterA) \
	visit(GetDefaultPrinterW) \
	visit(SetDefaultPrinterW) \
	visit(EnumPortsW) \
	visit(EnumPrintProcessorDatatypesA) \
	visit(EnumPrintProcessorDatatypesW) \
	visit(EnumPrintProcessorsA) \
	visit(EnumPrintProcessorsW) \
	visit(EnumPrinterDataA) \
	visit(EnumPrinterDataExA) \
	visit(EnumPrinterDataExW) \
	visit(EnumPrinterDataW) \
	visit(EnumPrinterDriversA) \
	visit(EnumPrinterDriversW) \
	visit(EnumPrinterKeyA) \
	visit(EnumPrinterKeyW) \
	visit(EnumPrintersA) \
	visit(EnumPrintersW) \
	visit(ExtDeviceMode) \
	visit(FindClosePrinterChangeNotification) \
	visit(FindFirstPrinterChangeNotification) \
	visit(FindNextPrinterChangeNotification) \
	visit(FlushPrinter) \
	visit(FreePrintNamedPropertyArray) \
	visit(FreePrintPropertyValue) \
	visit(FreePrinterNotifyInfo) \
	visit(GetCorePrinterDriversA) \
	visit(GetCorePrinterDriversW) \
	visit(GetFormA) \
	visit(GetFormW) \
	visit(GetJobA) \
	visit(GetJobNamedPropertyValue) \
	visit(GetJobW) \
	visit(GetPrintExecutionData) \
	visit(GetPrintOutputInfo) \
	visit(GetPrintProcessorDirectoryA) \
	visit(GetPrintProcessorDirectoryW) \
	visit(GetPrinterA) \
	visit(GetPrinterDataA) \
	visit(GetPrinterDataExA) \
	visit(GetPrinterDataExW) \
	visit(GetPrinterDataW) \
	visit(GetPrinterDriver2A) \
	visit(GetPrinterDriver2W) \
	visit(GetPrinterDriverA) \
	visit(GetPrinterDriverDirectoryA) \
	visit(GetPrinterDriverDirectoryW) \
	visit(GetPrinterDriverPackagePathA) \
	visit(GetPrinterDriverPackagePathW) \
	visit(GetPrinterDriverW) \
	visit(GetPrinterW) \
	visit(GetSpoolFileHandle) \
	visit(InstallPrinterDriverFromPackageA) \
	visit(InstallPrinterDriverFromPackageW) \
	visit(IsValidDevmodeA) \
	visit(IsValidDevmodeW) \
	visit(OpenPrinter2A) \
	visit(OpenPrinter2W) \
	visit(OpenPrinterA) \
	visit(OpenPrinterW) \
	visit(PlayGdiScriptOnPrinterIC) \
	visit(PrinterMessageBoxA) \
	visit(PrinterMessageBoxW) \
	visit(PrinterProperties) \
	visit(ReadPrinter) \
	visit(RegisterForPrintAsyncNotifications) \
	visit(ReportJobProcessingProgress) \
	visit(ResetPrinterA) \
	visit(ResetPrinterW) \
	visit(ScheduleJob) \
	visit(SeekPrinter) \
	visit(SetFormA) \
	visit(SetFormW) \
	visit(SetJobA) \
	visit(SetJobNamedProperty) \
	visit(SetJobW) \
	visit(SetPortA) \
	visit(SetPortW) \
	visit(SetPrinterA) \
	visit(SetPrinterDataA) \
	visit(SetPrinterDataExA) \
	visit(SetPrinterDataExW) \
	visit(SetPrinterDataW) \
	visit(SetPrinterW) \
	visit(SplDriverUnloadComplete) \
	visit(SpoolerPrinterEvent) \
	visit(StartDocDlgA) \
	visit(StartDocPrinterA) \
	visit(StartDocPrinterW) \
	visit(StartPagePrinter) \
	visit(UnRegisterForPrintAsyncNotifications) \
	visit(UploadPrinterDriverPackageA) \
	visit(UploadPrinterDriverPackageW) \
	visit(WaitForPrinterChange) \
	visit(WritePrinter) \
	visit(XcvDataW)

#undef DeviceCapabilities

namespace winspool
{
	class winspool_dll
	{
	public:
		HMODULE dll = nullptr;
		VISIT_WINSPOOL_PROCS(ADD_FARPROC_MEMBER);

		void Load()
		{
			// Load real dll
			dll = Wrapper::LoadDll(dtype.winspool);

			// Load dll functions
			if (dll)
			{
				VISIT_WINSPOOL_PROCS(LOAD_ORIGINAL_PROC);
			}
		}
	};

	extern winspool_dll module;
}
