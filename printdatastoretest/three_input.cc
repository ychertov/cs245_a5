#include "../printdatastore.h"
#include "../printdatastore.cc"
#include <iostream>

/*
 *	PrintDataStoreTest: No Input
 *
 *	empty print test, makes sure it prints a tab
 *	
 */


int main(int argc, char* argv[]) {
	PrintDataStore p;
	char state;
	int v1;
	int v2;

	std::cin >> state;
	std::cin >> v1;
	std::cin >> v1;

	p.setData(state, v1, v2);
	std::cout << p;
	return 0;
}
