#include "SMManager.h"
#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<string> a;
	a.insert("123");

	set<string> c;
	c.insert(a.begin(), a.end());

	for (auto& b : c)
		cout << b;

	return 0;
}