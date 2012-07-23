//produces random new quantities of each flavour of soda, [0, MaxShippedPerFlavour]

#include "bottlingplant.h"
#include "nameserver.h"
#include "flavours.h"
#include "PRNG.h"
#include "truck.h"

extern PRNG prng;

void BottlingPlant::produce() {
	unsigned int sum = 0;
	for (int i = 0; i < FlavourInfo::FLAVOUR_LENGTH; i++) {
		stock[i] = prng(maxShippedPerFlavour);
		sum += stock[i];
	}
	prt.print(KIND, MAKING_SODA, sum);
}

BottlingPlant::BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines, unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, unsigned int timeBetweenShipments ) : prt(prt), nameServer(nameServer), numVendingMachines(numVendingMachines), maxShippedPerFlavour(maxShippedPerFlavour), maxStockPerFlavour(maxStockPerFlavour), timeBetweenShipments(timeBetweenShipments) {
	prt.print(KIND, START);
	truck = new Truck(prt, nameServer, *this, numVendingMachines, maxStockPerFlavour);
	produce();
	truck->action();
}

BottlingPlant::~BottlingPlant() {
	prt.print(KIND, FINISHED);
	delete truck;
}

void BottlingPlant::getShipment( unsigned int cargo[] ) {
	for (int i = 0; i < FlavourInfo::FLAVOUR_LENGTH; i++) {
		cargo[i] = stock[i];
		stock[i] = 0;
	}
	prt.print(KIND, SHIPMENT_PICKED_UP);
}

void BottlingPlant::action() {
	if (prng(5) == 0) {
		prt.print(KIND, STRIKE);
		return;
	}
	
	if (prng(timeBetweenShipments-1) == 0) {
		return;
	}
	
	produce();	
	truck->action();
}

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
