#include "../printdatastore.h"
#include "../printdatastore.cc"
#include <iostream>

/*
 *	PrintDataStoreTest: No Input
 *
 *	empty print test, makes sure it prints a tab
 *	
 */


int main() {
	PrintDataStore p;
	char state;
	int v1;

	std::cin >> state;
	std::cin >> v1;

	p.setData(state, v1);
	std::cout << p;
	return 0;
}
