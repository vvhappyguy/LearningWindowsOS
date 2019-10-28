#ifndef REGISTRY_H
#define REGISTRY_H

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <tlhelp32.h>
#include <string>
#include <inttypes.h>

class Registry
{
private:
    HKEY destination;
    HKEY kHey;
    std::wstring keyName;
public:
    Registry() = delete;
    Registry(HKEY dest, std::wstring);
    ~Registry();

    static uint8_t openKey( HKEY   _hKey, LPCSTR _lpSubKey, PHKEY  _phkResult);
    static uint8_t openKey( HKEY  _hKey, LPCWSTR _lpSubKey,PHKEY   _phkResult);

};

#endif // REGISTRY_H
