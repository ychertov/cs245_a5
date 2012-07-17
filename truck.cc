#include "truck.h"

Truck::Truck( printer &prt, NameServer &nameServer, BottlingPlant &plant, unsigned int numVendingMachines, unsigned int maxStockPerFlavour ) {
	this->prt = prt;
	this->ns = nameSever;
	this->plant = plant;
	this->prt.print(KIND, START);
}

void Truck::action() {
}
