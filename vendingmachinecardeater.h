#ifndef __VENDINGMACHINECARDEATER_H__
#define __VENDINGMACHINECARDEATER_H__

#include "vendingmachine.h"
#include "printer.h"
#include "nameserver.h"
#include "flavours.h"
#include "watcard.h"

class VendingMachineCardEater : public VendingMachine {
		/*
			-->Derived Class from VendingMachine.
			-->There is a 1/10 Chance that this vending machine
		*/
	
	public:
		VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
		/*
			-->Contructor
				*PRECONDITIONS:
					- NameServer
					- Id
					- sodaCost
					- maxStockPerFlavour
				*POSTCONDITIONS:
					-N/A
		*/
		VendingMachine::Status buy( Flavours flavour, WATCard *&card );
		/*
			-->Buys a pop
			*PPRECONDITIONS:
				- Flavour
				- card (this WATCard cannot be NULL)
			*POSTCONDITIONS:
				-1/10 Chance that the students WATcard will be set to NULL
		*/
};
#endif
