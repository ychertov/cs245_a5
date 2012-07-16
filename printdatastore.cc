#include <assert.h>
#include "printdatastore.h"

PrintDataStore::PrintDataStore(){}

PrintDataStore::PrintDataStore(const PrintDataStore& pds) {
	state = pds.state;
	value1 = pds.value1;
	value2 = pds.value2;
}

void PrintDataStore::setData(char st) {
	assert(!state.first);
	state.first = true;
	state.second = st;
}

void PrintDataStore::setData(char st, int v1) {
	assert(!value1.first);
	setData(st);
	
	value1.first = true;
	value1.second = v1;
}

void PrintDataStore::setData(char st, int v1, int v2) {
	assert(!value2.first);
	setData(st, v1);

	value2.first = true;
	value2.second = v2;
}

void PrintDataStore::clear() {
	state.first = false;
	value1.first = false;
	value2.first = false;
}

std::ostream& operator<<( std::ostream& os, const PrintDataStore& pds ) {
	if (pds.state.first)
		os << pds.state.second;

	if (pds.value1.first)
		os << pds.value1.second;

	if (pds.value2.first)
		os << "," << pds.value2.second;

	os << "\t";
	
	return os;
}

