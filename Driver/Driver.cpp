#include <ntddk.h>

void DriverUnload(_In_ PDRIVER_OBJECT DriverObject);

/*
	TODO: Write function that prints Windows OS version: major, minor and build number.
	Using RtlGetVersion and KdPrint for output
*/
void PrintWindowsVersion();

NTSTATUS DriverCreateClose(_In_ PDEVICE_OBJECT DeviceObject, _In_ PIRP Irp);
NTSTATUS DriverDeviceControl(_In_ PDEVICE_OBJECT DeviceObject, _In_ PIRP Irp);

extern "C"
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = DriverUnload;

	DriverObject->MajorFunction[IRP_MJ_CREATE] = DriverCreateClose;
	DriverObject->MajorFunction[IRP_MJ_CLOSE] = DriverCreateClose;

	DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DriverDeviceControl;

	return STATUS_SUCCESS;
};

_Use_decl_annotations_
NTSTATUS DriverCreateClose(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	UNREFERENCED_PARAMETER(DeviceObject);
	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

_Use_decl_annotations_
NTSTATUS DriverDeviceControl(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	UNREFERENCED_PARAMETER(DeviceObject);
	// get our IO_STACK_LOCATION
	// auto stack = IoGetCurrentIrpStackLocation(Irp); // IO_STACK_LOCATION*
	auto status = STATUS_SUCCESS;

	//switch (stack->Parameters.DeviceIoControl.IoControlCode) 
	//{
	//	case IOCTL_PRIORITY_BOOSTER_SET_PRIORITY:
	//		// do the work
	//		break;
	//default:
	//	status = STATUS_INVALID_DEVICE_REQUEST;
	//	break;
	//}

	Irp->IoStatus.Status = status;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return status;
}


void DriverUnload(_In_ PDRIVER_OBJECT DriverObject)
{
	UNREFERENCED_PARAMETER(DriverObject);
}