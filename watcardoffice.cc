#include "watcardoffice.h"
#include "watcard.h"
#include "printer.h"
#include "PRNG.h"
#include "debug.h"
#include <iostream> 

extern PRNG prng;
static const int CHANCE = 3; //1 in 4 chance (3 = 4 - 1)

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
	if( prng(CHANCE) == 0) {//one in 4 chances of halfing amount
		DEBUG(std::cout << "Halfing the money" << std::endl);
		amount/=2;
	} else {
		DEBUG(std::cout << "not halving the money" << std::endl);
	}	
	card.credit(amount);
	prt.print(KIND, END_TRANSFER, id, amount);
	std::cout << "End Balance: " << card.getBalance();
}

WATCardOffice::~WATCardOffice() {
	prt.print(KIND, FINISH);
}

