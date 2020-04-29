#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>

#include "Writer.h"

// Class for creating, managing SharedMemory and creating Writers/Reader of created SM-Object
class SMManager
{
private:
	DWORD size = MAXDWORD; // Size of SM
	DWORD min = 0; // ...
	HANDLE hMapFile = nullptr; // ... SM Handle
	std::wstring name; // ... Name of SM
public:
	SMManager(std::wstring&, DWORD); // C-tor name + size
	~SMManager(); // D-tor
	int createSM();
	int closeSM();

	SMManager() = delete;
	SMManager(const SMManager&) = delete;
	SMManager& operator=(const SMManager&) = delete;
};

