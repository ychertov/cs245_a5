#ifndef __VENDINGMACHINECARDEATER_H__
#define __VENDINGMACHINECARDEATER_H__

#include "printer.h"
#include "nameserver.h"
#include "flavours.h"
#include "watcard.h"

class VendingMachineCardEater : public VendingMachine {
	
	public:
		VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );

	Status buy ( Flavours flavour, WATCard *&card );
		/*
			Overrides Vending machine buy, has a 1 in 10 chance to nullify card
		*/
};
#endif
