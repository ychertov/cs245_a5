#include "printer.h"
#include "watcard.h"

class WATCardOffice {//used by a student to create a WATCARD with an initial deposit and transfer funds to their WATCard to buy a soda.
	private:
		Printer &prt;
	public:
		WATCardOffice( Printer &prt );//constructor

		WATCard *create( unsigned int id, unsigned int amount );

		void transfer( unsigned int id, unsigned int amount, WATCard &card);
}
