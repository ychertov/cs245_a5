#include "vendingmachine.h"
#include "flavours.h"
#include "watcard.h"
#include "printer.h"
#include "nameserver.h"
#include "debug.h"

VendingMachine::VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ) : prt(prt), nameServer(nameServer), id(id), sodaCost(sodaCost), maxStockPerFlavour(maxStockPerFlavour) {
	/*
		Contructor for VendingMachine
	*/

	DEBUG(std::cout << "cost method: " << cost() << std::endl);
	DEBUG(std::cout << "cost variable: " << sodaCost << std::endl);
	this->prt.print(KIND, id, START, cost());
	
	//initilize inventory
	this->inv = new unsigned int[FlavourInfo::FLAVOUR_LENGTH];//# of different flavours
	this->inv[BLUES_BLACK_CHERRY] = 0; //all the flavours initialize to 0.
	this->inv[CLASSICAL_CREAM_SODA] = 0;
	this->inv[ROCK_ROOT_BEER] = 0;
	this->inv[JAZZ_LIME] = 0;
	
	nameServer.VMregister(this);
	
	
/*
	Set stock to 0	
	egister with nameserver
*/
}
VendingMachine::~VendingMachine() {//destructor
	delete inv;
	prt.print(KIND, id, FINISHED);//update status
}

VendingMachine::Status VendingMachine::buy( Flavours flavour, WATCard *&card ) {
	if (inv[flavour] == 0) // if flavour not in stock
		return STOCK;

	if ((*card).getBalance() < cost()) //if student does not have enough money
		return FUNDS;

	inv[flavour]--;
	(*card).debit(cost());
	prt.print(KIND, id, SODA_BOUGHT, flavour, inv[flavour]);
	return BUY;
/*
	If the specified soda is unavailable or the student has insufficient funds to purchase the soda, buy returns STOCK
	or FUNDS; otherwise, WATCard is debited by the cost of a soda and buy returns BUY.
*/
}
unsigned int *VendingMachine::inventory() {
	prt.print(KIND, id, RELOADING);
	return inv;
/*
	return a pointer to an array containing the amount of each kind of soda currently in the vending machine
*/
}

void VendingMachine::restocked() {
	prt.print(KIND, DONE_RELOADING);
/*
	called to indicate the restocking is complete.
*/
}

unsigned int VendingMachine::cost() {
	return sodaCost;
}

unsigned int VendingMachine::getId() {
	return id;
}
