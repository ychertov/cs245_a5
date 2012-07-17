//This is the header file bottlingplant.h (this is the interface for the class BottlingPlant.h
#ifndef BOTTLINGPLANT_H
#define BOTTLINGPLANT_H

#include "printer.h"
#include "nameserver.h"

class BottlingPlant {//produces random new quantities of each flavour of soda, [0, MaxShippedPerFlavour]
	private:
		Printer &prt;
		NameServer &nameServer;
		
		unsigned int numVendingMachines;
		unsigned int maxShippedPerFlavour;
		unsigned int maxStockPerFlavour;
		unsigned int timeBetweenShipments;

	public:
		BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines, unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, unsigned int timeBetweenShipments );

		void getShipment( unsigned int cargo[] );
		void action();
};

#endif //BOTTLINGPLANT

/*
--> The bottling plant
begins by creating a truck, performing a production run, and distributing these bottles to initialize the registered
vending machines using the truck. Subsequently, the bottling plant’s behaviour is deﬁned by member action as
follows.

-->There is a 1 in 5 chance the bottling plant is on strike. If on strike, the bottling plant returns immediately
without doing any work; otherwise, the bottling plant checks if the truck has come back from the last delivery.

-->There is a 1 in TimeBetweenShipments chance the truck has returned. If the truck has returned, the bottling plant
performs a production run, and then calls the truck’s action routine to deliver the current production run to the
vending machines; otherwise, the bottling plant returns without doing any work. The truck calls getShipment
to obtain a shipment from the plant (i.e., the production run), and the shipment is copied into the cargo array
passed by the truck.
*/
