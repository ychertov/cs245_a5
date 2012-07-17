#include "watcardoffice.h"
#include "watcard.h"

WATCardOffice::WATCardOffice( Printer &prt ) {
	this->prt = prt;
	prt.print(WATCardOffice::KIND, 'S');
}

WATCard *WATCardOffice::create( unsigned int id, unsigned int amount ) {
	WATcard* w = new WATcard(0);
	w->id = id;
	w->amount = amount;
	return w;
}

void WATCardOffice::transfer( unsigned int id, unsigned int amount, WATCard &card) {

	if( prng(3) == 0){//one in 4 chances
		balance = balance + amount/2;	
	}
	else balance = balance + transfer;
}
