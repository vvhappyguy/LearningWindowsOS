#include "SMManager.h"

SMManager::SMManager(std::wstring& _nameSM, DWORD _sizeSM) : size(_sizeSM)
{
	this->name = _nameSM;
	this->hMapFile = nullptr;
}

SMManager::~SMManager()
{
	this->name.clear();
}

int SMManager::createSM()
{
	if (this->hMapFile != nullptr)
		return 0;
	this->hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size (high-order DWORD)
		this->size,                // maximum object size (low-order DWORD)
		this->name.c_str());                 // name of mapping object

	if (this->hMapFile == NULL)
	{
		return 0;
	}

	return 1;
}

int SMManager::closeSM()
{
	if (this->hMapFile != NULL)
	{
		CloseHandle(this->hMapFile);
		return 1;
	}
	return 0;
}
