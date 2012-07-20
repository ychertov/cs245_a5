#include "watcard.h"
#include <assert.h>

WATCard::WATCard() {
	balance = 0;
}

void WATCard::debit( unsigned int amount) {
	assert(balance >= amount);
	balance -= amount;
}

void WATCard::credit( unsigned int amount) {
	balance += amount;
}

unsigned int WATCard::getBalance() const {
	return balance;
}
