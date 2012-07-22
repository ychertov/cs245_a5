#ifndef __VENDINGMACHINE_H__
#define __VENDINGMACHINE_H__

#include "flavours.h"
#include "watcard.h"
#include "printer.h"
#include "nameserver.h"

class VendingMachine {
	protected:
		static const Printer::Kind KIND = Printer::Vending;
		
		static const char START = 'S';//State variables
		static const char RELOADING = 'r';
		static const char DONE_RELOADING = 'R';
		static const char SODA_BOUGHT = 'B';
		static const char FINISHED = 'F';

		Printer &prt;
		NameServer nameServer;
		unsigned int id;
		unsigned int sodaCost;
		unsigned int maxStockPerFlavour;
				
		unsigned int* inv;
				
	public:
		enum Status { BUY, STOCK, FUNDS };
			/*
				Pruchase Status:
					BUY: successful buy
					STOCK: out of stock
					FUNDS: insufficient funds			
			*/
		VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
			/*
				Set stock to 0
				Register with nameserver
			*/

		virtual ~VendingMachine();

		virtual Status buy( Flavours flavour, WATCard *&card );
			/*
				If the specified soda is unavailable or the student has insufficient funds to purchase the soda, buy returns STOCK
				or FUNDS; otherwise, WATCard is debited by the cost of a soda and buy returns BUY.
			*/

		virtual unsigned int *inventory();
			/*
				return a pointer to an array containing the amount of each kind of soda currently in the vending machine
			*/

		virtual void restocked();
			/*
				called to indicate the restocking is complete.
			*/

		virtual unsigned int cost();
			/*
				returns the cost of purchasing a soda
			*/

		virtual unsigned int getId();
			/*
				returns Id
			*/
};
#endif
