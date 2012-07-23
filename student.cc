//This is the header file class.h (the interface for the class Student)

#include "student.h"
#include "PRNG.h"
#include "nameserver.h"
#include "printer.h"
#include "watcardoffice.h"
#include <iostream>
 
extern PRNG prng;

void Student::refreshMachine() {
	currentMachine = nameServer.getMachine(id);
	prt.print(KIND, id, SELECTING_VENDING, currentMachine->getId());
}	


Student::Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id, unsigned int maxPurchases ) : prt(prt), nameServer(nameServer), cardOffice(cardOffice), id(id) {
	purchasesRemaining = prng(maxPurchases) + 1;
	switch(prng(FlavourInfo::FLAVOUR_LENGTH)) {
		case 0:
			faveFlave = BLUES_BLACK_CHERRY; 
			break;
		case 1:
			faveFlave = CLASSICAL_CREAM_SODA;
			break;
		case 2:
			faveFlave = ROCK_ROOT_BEER;
			break;
		case 3:
			faveFlave = JAZZ_LIME;
			break;
	}
	prt.print(KIND, id, START, faveFlave, purchasesRemaining);
	watcard = cardOffice.create(id, 5);
	refreshMachine();
	/*
		**STUDENT CONTRUCTOR SPECIFICATIONS**
		-->id: [0, NumStudents)
		-->random number of bottles to purchase: [1, MaxPurchases]
		-->random favourite ﬂavour [0, 3]
		-->creating a WATCard (dynamically) with a $5 balance via the WATCardOfﬁce
		-->obtaining the location of a vending machine from the name server
	*/
}

void Student::makeTransfer(unsigned int amount) {
	prt.print(KIND, id, START_FUNDS_TRANSFER, amount);	
	cardOffice.transfer(id, amount, *watcard);
	prt.print(KIND, id, END_FUNDS_TRANSFER, watcard->getBalance());	
}
bool Student::action() {
	if (purchasesRemaining == 0)
		return false;

	VendingMachine::Status buyResult = currentMachine->buy(faveFlave, watcard);
	if (watcard == NULL) {
		prt.print(KIND, id, WATCARD_DESTROYED);
		watcard = cardOffice.create(id, 5);
	}

	switch(buyResult) {
		case VendingMachine::BUY:
			purchasesRemaining--;
			prt.print(KIND, id, BOUGHT, watcard->getBalance());
			break;
		case VendingMachine::FUNDS:
			while (currentMachine->cost() > watcard->getBalance()) {
				makeTransfer(3);
			}
			break;
		case VendingMachine::STOCK:
			refreshMachine();
			break;	 
	}

	return true;
	/*
		*FALSE:-->When a student has purchased all the soda initially selected
		*TRUE:-->If the vending machine delivered a bottle of soda, the student drinks it and returns true.
	*/
}

Student::~Student() {
	prt.print(KIND, id, FINISH);
}
