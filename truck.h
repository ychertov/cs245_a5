//This is a header file for the Truck class.

#ifndef _TRUCK_H_
#define _TRUCK_H_

#include "printer.h"
#include "nameserver.h"
#include "bottlingplant.h"

class Truck {//moves soda from the bottling plant to the vending machine.
	private:
		static const Printer::Kind KIND = Printer::Truck;

		static const char START = 'S';//states
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
		
		unsigned int getCargoVolume(unsigned int cargo[]);
		void restock(VendingMachine* vm, unsigned int cargo[]);
	public:
		Truck( Printer& prt, NameServer& nameServer, BottlingPlant &plant, unsigned int numVendingMachines, unsigned int maxStockPerFlavour );
		void action();
		/*	-->defines the truck's behaviour
			Preconditions:N/A
			Postconditions:N/A
		*/
		~Truck();//destructor
};

#endif //TRUCK_H
