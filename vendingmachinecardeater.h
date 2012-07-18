#ifndef __VENDINGMACHINECARDEATER_H__
#define __VENDINGMACHINECARDEATER_H__

#include "vendingmachine.h"
#include "printer.h"
#include "nameserver.h"
#include "flavours.h"
#include "watcard.h"

class VendingMachineCardEater : public VendingMachine {
	
	public:
		VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
		VendingMachine::Status buy( Flavours flavour, WATCard *&card );
};
#endif
