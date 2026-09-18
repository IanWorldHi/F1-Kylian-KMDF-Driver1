#include <ntddk.h> //core windows kernel definitions for all drivers
#include <wdf.h>   //definitions for Windows Driver Framework (WDF) drivers
// ^^ included with "Additional Include Directors"

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD KmdfHelloWorldEvtDeviceAdd;

NTSTATUS
DriverEntry(  //entrypoint for driver basically main()
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{ 
	//success or failure
	NTSTATUS status = STATUS_SUCCESS; 

	//Allocate config obj
	WDF_DRIVER_CONFIG config;

	//Print
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: DriverEntry called\n"));


	WDF_DRIVER_CONFIG_INIT(&config, KmdfHelloWorldEvtDeviceAdd);

	//create driver obj
	status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);
	return status;
}

NTSTATUS
KmdfHelloWorldEvtDeviceAdd(
	_In_ WDFDRIVER Driver,
	_Inout_ PWDFDEVICE_INIT DeviceInit
)
{
	UNREFERENCED_PARAMETER(Driver);
	NTSTATUS status;
	WDFDEVICE hDevice;
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: KmdfHelloWorldEvtDeviceAdd called\n"));
	status = WdfDeviceCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES, &hDevice);
	return status;
}
















