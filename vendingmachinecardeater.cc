#include "vendingmachinecardeater.h"

VendingMachineCardEater::VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ) {
}

Status VendingMachineCardEater::buy( Flavours flavour, WATCard *&card ) {
/*
	Overrides Vending machine buy, has a 1 in 10 chance to nullify card
*/
}
