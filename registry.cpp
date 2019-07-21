#include "registry.h"

Registry::Registry(HKEY dest, std::wstring keyName)
{
    LPWSTR keyNameLPW = (LPWSTR)(keyName.c_str());
    if(RegOpenKey(dest, keyNameLPW, &(this->kHey)) == ERROR_SUCCESS)
        std::wcout << L"Key[" << keyName << L"] opened successfully." << std::endl;
    else {
        std::wcout << L"No such (" << keyName << ") key. Do you want to create it?(Yes/No)" << std::endl;
        std::wstring answ;
        std::wcin >> answ;
        if(answ == L"Yes")
        {
            if(RegCreateKey(dest,keyNameLPW,&(this->kHey)) == ERROR_SUCCESS)
            {
                std::wcout << L"Key["<< keyName << L"] created successfully." << std::endl;
            }
            else {
                std::wcout << L"Can't create such key" << std::endl;
            }
        }
    }
}


