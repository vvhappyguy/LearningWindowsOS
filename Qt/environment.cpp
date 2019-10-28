#include "environment.h"

Enviroment::Enviroment()
{

}

void Enviroment::printEnviromentVariables()
{
    LPWCH envStr = GetEnvironmentStrings();
    std::wcout << "Envirmoent Strings : " << envStr << std::endl;
    return;
}
