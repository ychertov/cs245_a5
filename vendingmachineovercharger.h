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
		/*
		-->Constructor
			*PRECONDITIONS:
				-N/A

			*POSTCONTITIONS:
				-N/A
		*/
		
		unsigned int cost();
		/*	
		-->returns the cost of the soda drink x 2
			*PRECONDITIONS:
				-N/A
			*POSCONDITIONS:
				-returns 2x the cost of the soda
		*/
};
#endif
