#ifndef REGISTRY_H
#define REGISTRY_H

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <tlhelp32.h>
#include <string>

class Registry
{
private:
    HKEY kHey;
public:
    Registry() = delete;
    Registry(HKEY dest, std::wstring);


};

#endif // REGISTRY_H
