#include <ntddk.h> //core windows kernel definitions for all drivers
#include <wdf.h>   //definitions for Windows Driver Framework (WDF) drivers
// ^^ included with "Additional Include Directors"

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD KmdfHelloWorldEvtDeviceAdd;

NTSTATUS
DriverEntry( 
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{ 
	NTSTATUS status = STATUS_SUCCESS;

}















