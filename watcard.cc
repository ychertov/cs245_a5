#include "watcard.h"

WATCard::WATCard() {
	balance = 0;
}

void WATCard::debit( unsigned int amount) {
	balance -= amount;
}

void WATCard::credit( unsigned int amount) {
	balance += amount;
}

unsigned int WATCard::getBalance() const {
	return balance;
}
