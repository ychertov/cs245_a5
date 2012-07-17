//This is a header file for the Truck class.

#ifndef TRUCK_H
#define TRUCK_H

#include "printer.h"
#include "nameserver.h"
#include "bottlingplant.h"

class Truck {//moves soda from the bottling plant to the vending machine.
	private:
		static const Printer::Kind KIND = Printer::Truck;

		static const char START = 'S';
		static const char PICKED_UP_SHIPMENT = 'P';
		static const char BEGIN_DELIVERY = 'd';
		static const char UNSUCCESS_FILLING = 'U';
		static const char END_DELIVERY = 'D';
		static const char FINISHED = 'F';

		Printer& prt;
		NameServer& nameServer;
		BottlingPlant &plant;
		unsigned int numVendingMachines;
		unsigned int maxStockPerFlavour;
	public:
		Truck( Printer& prt, NameServer& nameServer, BottlingPlant &plant, unsigned int numVendingMachines, unsigned int maxStockPerFlavour );
		void action();//defines the truck's behaviour.
};

#endif //TRUCK_H
