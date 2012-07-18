#ifndef __WATCARD_OFFICE_
#define __WATCARD_OFFICE_

#include "printer.h"
#include "watcard.h"

class WATCardOffice {//used by a student to create a WATCARD with an initial deposit and transfer funds to their WATCard to buy a soda.
	private:
		static const Printer::Kind KIND = Printer::WATCardOffice;

		static const char START = 'S';
		static const char CREATING = 'C';
		static const char BEGIN_TRANSFER = 't';
		static const char END_TRANSFER = 'T';
		static const char FINISH = 'F';

		Printer &prt;

	public:
		WATCardOffice( Printer &prt );//constructor

		WATCard *create( unsigned int id, unsigned int amount );

		void transfer( unsigned int id, unsigned int amount, WATCard &card);
		
		~WATCardOffice();
};

#endif
