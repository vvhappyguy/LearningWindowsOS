#include "SMManager.h"
#include <iostream>

int main()
{
	std::wstring a(L"das");
	SMManager* sm = new SMManager(a, 1);
	std::cout << "create:" << sm->createSM() << std::endl;
	std::cout << "close:" << sm->closeSM() << std::endl;
	delete sm;

	return 0;
}