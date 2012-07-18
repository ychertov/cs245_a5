#ifndef __VENDINGMACHINEOVERCHARGER_H__
#define __VENDINGMACHINEOVERCHARGER_H__

#include "vendingmachine.h"
#include "printer.h"
#include "nameserver.h"

class VendingMachineOverCharger : public VendingMachine {
	private:
		unsigned int sodaCost;	
	public:
		VendingMachineOverCharger( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );

		unsigned int cost();
		/*
			returns 2x the cost of the soda
		*/
};
#endif
