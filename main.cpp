#include <QCoreApplication>

#include "version.h"
#include "registry.h"

#include <iostream>
#include <vector>
#include <bitset>
#include <array>
#include <string>
#include <intrin.h>

int main(int argc, char *argv[])
{
    int CPUID[4] = {-1};
    __cpuid(CPUID, 1);
    for(int i: CPUID)
        std::cout << std::bitset<32>(i) << endl;
    int a1 = CPUID[1];
    int a2 = (CPUID[2] >> 31);
    std::cout << std::bitset<32>(a1) << " " << std::bitset<32>(a2) << std::endl;
    QCoreApplication a(argc, argv);
    return a.exec();
}
