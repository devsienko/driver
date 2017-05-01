
#include <ntddk.h>
#include <wdf.h>




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////
///	Объявления функций, определённых ниже.

EVT_WDF_DRIVER_DEVICE_ADD  EvtDriverDeviceAdd;




/////////////////////////////////////////////////////////////////////////////////////////////////
NTSTATUS 
DriverEntry(  _In_ DRIVER_OBJECT * pdriverobjectThe,  _In_ UNICODE_STRING * pusRegistryPath)
{
	NTSTATUS  statusReturn;
	WDF_DRIVER_CONFIG  driverconfigThe;

	KdPrintEx((  DPFLTR_IHVDRIVER_ID,  DPFLTR_INFO_LEVEL,  "HelloWorld: DriverEntry\n"));

	WDF_DRIVER_CONFIG_INIT(  & driverconfigThe,  & EvtDriverDeviceAdd);

	statusReturn = WdfDriverCreate(  pdriverobjectThe,  pusRegistryPath,
				WDF_NO_OBJECT_ATTRIBUTES,  & driverconfigThe,  WDF_NO_HANDLE  );

	return  statusReturn;
}




/////////////////////////////////////////////////////////////////////////////////////////////////
NTSTATUS 
EvtDriverDeviceAdd(  _In_ WDFDRIVER driver_,  _Inout_ struct WDFDEVICE_INIT * pdeviceinitThe)
{
	UNREFERENCED_PARAMETER( driver_);
	
	NTSTATUS  statusReturn;
	WDFDEVICE  deviceThe;

	KdPrintEx((  DPFLTR_IHVDRIVER_ID,  DPFLTR_INFO_LEVEL,  "HelloWorld: EvtDriverDeviceAdd\n"));

	statusReturn = WdfDeviceCreate(  & pdeviceinitThe,  WDF_NO_OBJECT_ATTRIBUTES,  & deviceThe);

	return  statusReturn;
}


//
