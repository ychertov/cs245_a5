#include "vendingmachine.h"
#include "flavours.h"
#include "watcard.h"
#include "printer.h"
#include "nameserver.h"

VendingMachine::VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockParFlavour ) {
/*
	Set stock to 0
	egister with nameserver
*/
}
VendingMachine::~VendingMachine() {
}

Status VendingMachine::buy( Flavours flavour, WATCard *&card ) {
/*
	If the specified soda is unavailable or the student has insufficient funds to purchase the soda, buy returns STOCK
	or FUNDS; otherwise, WATCard is debited by the cost of a soda and buy returns BUY.
*/
}
unsigned int *VendingMachine::inventory() {
/*
	return a pointer to an array containing the amount of each kind of soda currently in the vending machine
*/
}

void VendingMachine::restocked() {
/*
	called to indicate the restocking is complete.
*/
}

unsigned int VendingMachine::cost() {
/*
	returns the cost of purchasing a soda
*/
}

unsigned int VendingMachine::getId() {
/*
	returns Id
*/
}
