#include "watcardoffice.h"
#include "watcard.h"
#include "printer.h"
#include "PRNG.h"

extern PRNG prng;
static const int CHANCE = 3; //1 in 4 chance (3 = 4 - 1)

WATCardOffice::WATCardOffice( Printer &prt ) : prt(prt) {
	prt.print(KIND, START);
}

WATCard *WATCardOffice::create( unsigned int id, unsigned int amount ) {
	prt.print(KIND, CREATING, id, amount);
	WATCard* w = new WATCard();
	w->credit(amount);
	return w;
}

void WATCardOffice::transfer( unsigned int id, unsigned int amount, WATCard &card) {
	prt.print(KIND, BEGIN_TRANSFER, id, amount);
	if( prng(CHANCE) == 0)//one in 4 chances of halfing amount
		amount/=2;
		
	card.credit(amount);
	prt.print(KIND, END_TRANSFER, id, amount);
}

WATCardOffice::~WATCardOffice() {
	prt.print(KIND, FINISH);
}

