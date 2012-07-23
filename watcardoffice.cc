#include "watcardoffice.h"
#include "watcard.h"
#include "printer.h"
#include "PRNG.h"
#include "debug.h"
#include <iostream> 

extern PRNG prng;
static const int CHANCE = 4; //1 in 4 chance

WATCardOffice::WATCardOffice( Printer &prt ) : prt(prt) {
	prt.print(KIND, START);
}

WATCard *WATCardOffice::create( unsigned int id, unsigned int amount ) {
	prt.print(KIND, CREATING, id, amount);
	DEBUG(std::cout << "Creding Watcard id: " << id << " amount: " << amount << std::endl);
	WATCard* w = new WATCard();
	w->credit(amount);
	return w;
}

void WATCardOffice::transfer( unsigned int id, unsigned int amount, WATCard &card) {
	prt.print(KIND, BEGIN_TRANSFER, id, amount);
	if( prng(CHANCE-1) == 0) {//one in 4 chances of halfing amount
		DEBUG(std::cout << "Halfing the money from " << amount);
		amount/=2;
		DEBUG(std::cout << " to " << amount << std::endl);
	} else {
		DEBUG(std::cout << "not halving the money " << amount << std::endl);
	}	
	card.credit(amount);
	prt.print(KIND, END_TRANSFER, id, amount);
	DEBUG(std::cout << "End Balance: " << card.getBalance());
}

WATCardOffice::~WATCardOffice() {
	prt.print(KIND, FINISH);
}

