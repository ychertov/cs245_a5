#include "vendingmachinecardeater.h"

static const int CHANCE = 9; //1 in 10 chance (9 = 10 - 1)

VendingMachineCardEater::VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ) : VendingMachine(prt, nameServer, id, sodaCoda, maxStockFlavour) {}

Status VendingMachineCardEater::buy( Flavours flavour, WATCard *&card ) {
	Status result = VendingMachine::buy(flavour, card); 
	if (result == BUY && (prng( CHANCE ) == 1) ) //if result is buy and machine decides to eat card
		card = null;
	return result;
}
