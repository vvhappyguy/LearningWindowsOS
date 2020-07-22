#include <ntddk.h>

void SampleUnload(_In_ PDRIVER_OBJECT DriverObject);

extern "C"
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = SampleUnload;
	
	return STATUS_SUCCESS;
};


void SampleUnload(_In_ PDRIVER_OBJECT DriverObject) 
{
	UNREFERENCED_PARAMETER(DriverObject);
}