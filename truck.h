//This is a header file for the Truck class.

#ifndef TRUCK_H
#define TRUCK_H

#include "printer.h"
#include "nameserver.h"
#include "bottlingplant.h"

class Truck {//moves soda from the bottling plant to the vending machine.
	public:
		Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant, unsigned int numVendingMachines, unsigned int maxStockPerFlavour );
		void action();//defines the truck's behaviour.
}

#endif //TRUCK_H
