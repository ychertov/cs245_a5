#include "debug.h"
#include "vendingmachineovercharger.h"
#include "nameserver.h"
#include <iostream>
VendingMachineOverCharger::VendingMachineOverCharger( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ) : VendingMachine(prt, nameServer, id, sodaCost, maxStockPerFlavour) {
	this->prt.print(KIND, id, START, cost());
	nameServer.VMregister(this);
}

unsigned int VendingMachineOverCharger::cost() {
//	DEBUG(std::cout << "soda cost is " << sodaCost << " but im doubling it to " << (sodaCost *2) << std::endl);
	return (sodaCost*2);
}
