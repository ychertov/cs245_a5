#include "vendingmachinecardeater.h"
#include "PRNG.h"
#include "debug.h"
#include <iostream>

static const int CHANCE = 9; //1 in 10 chance (9 = 10 - 1)
extern PRNG prng;

VendingMachineCardEater::VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ) : VendingMachine(prt, nameServer, id, sodaCost, maxStockPerFlavour) {
	this->prt.print(KIND, id, START, cost());
	nameServer.VMregister(this);
}

VendingMachine::Status VendingMachineCardEater::buy( Flavours flavour, WATCard *&card ) {
	Status result = VendingMachine::buy(flavour, card); 
	if (result == BUY && (prng( CHANCE ) == 0) ) {//if result is buy and machine decides to eat card
		delete card; 	
		card = NULL;
	}
	return result;
}

unsigned int VendingMachineCardEater::cost() {
	return sodaCost;
}
