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
	const PrintDataStore p;
	std::cout << p << std::endl;
	return 0;
}
