#include "version.h"

Version::Version()
{

}

void Version::printVersion()
{
    cout << "Version::printVersion()" << endl;

    cout << "It's Windows: ";
    if (IsWindowsServer())
        cout << "Server";
    else if(IsWindows10OrGreater())
        cout << "10orGreater";
    else if(IsWindows8Point1OrGreater())
        cout << "8.1";
    else if(IsWindows8OrGreater())
        cout << "8";
    else if(IsWindows7SP1OrGreater())
        cout << "7 (Service Pack 1)";
    else if(IsWindows7OrGreater())
        cout << "7";
    else if(IsWindowsVistaSP2OrGreater())
        cout << "Vista (Service Pack 2)";
    else if(IsWindowsVistaSP1OrGreater())
        cout << "Vista (Service Pack 1)";
    else if(IsWindowsVistaOrGreater())
        cout << "Vista";
    else if(IsWindowsXPSP3OrGreater())
        cout << "XP (Service Pack 3)";
    else if (IsWindowsXPSP2OrGreater())
        cout << "XP (Service Pack 2)";
    else if (IsWindowsXPSP1OrGreater())
        cout << "XP (Service Pack 1)";
    else if (IsWindowsXPOrGreater())
        cout << "XP";
    else if (IsWindowsThresholdOrGreater())
        cout << "?? Threshold??";
    cout << endl;
}
