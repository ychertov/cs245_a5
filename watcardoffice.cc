//This is the header file for WATCardOffice. (the interface for the class WATCardOffice)

#ifndef WATCARDOFFICE_H
#define WATCARDOFFICE_H

#include "printer.h"
#include "watcard.h"

class WATCardOffice {//used by a student to create a WATCARD with an initial deposit and transfer funds to their WATCard to buy a soda.
	public:
	WATCardOffice( Printer &prt );//constructor
	WATCard *create( unsigned int id, unsigned int amount );
	void transfer( unsigned int id, unsigned int amount, WATCard &card);
}

#endif //WATCARDOFFICE_H
