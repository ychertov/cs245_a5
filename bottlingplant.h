//This is the header file bottlingplant.h (this is the interface for the class BottlingPlant.h
#ifndef BOTTLINGPLANT_H
#define BOTTLINGPLANT_H

#include "printer.h"
#include "nameserver.h"

class Truck;

class BottlingPlant {//produces random new quantities of each flavour of soda, [0, MaxShippedPerFlavour]
	private:
		static const Printer::Kind KIND = Printer::BottlingPlant;

		static const char START = 'S';//states
		static const char STRIKE = 'X';
		static const char MAKING_SODA = 'G';
		static const char SHIPMENT_PICKED_UP = 'P';
		static const char FINISHED = 'F';
	
		Printer& prt;
		NameServer& nameServer;
		Truck* truck;
		
		unsigned int stock[3];

		unsigned int numVendingMachines;
		unsigned int maxShippedPerFlavour;
		unsigned int maxStockPerFlavour;
		unsigned int timeBetweenShipments;

		void produce();
		/*
			-->stocks the bottles (random ammount)and prints to the print function
			*PRECONDITIONS:
				->N/A
			*POSTCONDITIONS:
				->N/A
		*/
	public:
		BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines, unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, unsigned int timeBetweenShipments );
		/*
			-->Constructor
			*PRECONDITIONS:
				->N/A
			*POSTCONDITIONS
				->N/A
		*/
		void getShipment( unsigned int cargo[] );
		/*
			-->Gets the shipment from the plant and then copied into the cargo array
			*PRECONDITIONS:
				->Cargo must be an array of length 4 (the # of flavours)
			*POSTCONDITIONS:
				->N/A
		*/
		void action();
		/*
			-->Defines the bottleling plants behaviour:
				* 1/5 chance it will be on strike
				* 1/(Time between shipment chance)
			*PRECONDITIONS:
				->timeBetweenShipments [1, INT_MAX)
			*POSTCONDITIONS:
				->N/A
		*/
		~BottlingPlant();
		/*
			Destructor
		*/
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
