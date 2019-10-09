#include "registry.h"

Registry::Registry(HKEY _dest, std::wstring _keyName)
{
    LPWSTR keyNameLPW = (LPWSTR)(_keyName.c_str());
    if(RegOpenKey(_dest, keyNameLPW, &(this->kHey)) == ERROR_SUCCESS)
    {
        this->destination = _dest;
        this->keyName = _keyName;
        std::wcout << L"Key[" << _keyName << L"] opened successfully." << std::endl;
    }
    else
    {
        std::wcout << L"No such (" << _keyName << ") key. Do you want to create it?(Yes/No)" << std::endl;
        std::wstring answ;
        std::wcin >> answ;
        if(answ == L"Yes")
        {
            if(RegCreateKey(_dest,keyNameLPW,&(this->kHey)) == ERROR_SUCCESS)
            {
                this->destination = _dest;
                this->keyName = _keyName;
                std::wcout << L"Key["<< _keyName << L"] created successfully." << std::endl;
            }
            else {
                std::wcout << L"Can't create such key" << std::endl;
            }
        }
    }
}

Registry::~Registry()
{
    this->keyName = L"";
    this->kHey = nullptr;
    this->destination = nullptr;
}

static bool openKey( HKEY   _hKey, LPCSTR _lpSubKey, PHKEY  _phkResult)
{
    if(RegOpenKeyA(_hKey, _lpSubKey, _phkResult) == ERROR_SUCCESS){
        return true;
    }
    else {
        return false;
    }

}

static bool openKey( HKEY  _hKey, LPCWSTR _lpSubKey,PHKEY   _phkResult)
{
    if(RegOpenKeyW(_hKey, _lpSubKey, _phkResult) == ERROR_SUCCESS){
        return true;
    }
    else {
        return false;
    }
}

