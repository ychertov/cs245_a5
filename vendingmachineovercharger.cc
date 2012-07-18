#include "vendingmachineovercharger.h"
#include "nameserver.h"

VendingMachineOverCharger::VendingMachineOverCharger( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ) : VendingMachine(prt, nameServer, id, sodaCoda, maxStockFlavour) {}

unsigned int VendingMachineOverCharger::cost() {
	return sodaCost*2;
}
