#include "watcard.h"

WATCard::WATCard(int balance) {
	balance = 0;
}

void WATCard::debit( unsigned int amount) {
	balance = balance - amount;
}

void WATCard::credit( unsigned int amount) {
	balance = balance + amount;
}

unsigned int WATCard::getBalance() const {
	return balance;
}
