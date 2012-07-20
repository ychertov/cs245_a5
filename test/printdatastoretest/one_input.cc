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
	PrintDataStore p = PrintDataStore();
	char state;
	std::cin >> state;
	p.setData(state);
	std::cout << p;
	return 0;
}
