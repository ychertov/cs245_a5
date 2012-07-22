//This is the header file watcard.h (the interface for the class WATCard

#ifndef WATCARD_H
#define WATCARD_H

class WATCard{//Manages the money associated with the card.
	private:
		unsigned int balance;
	public:
		WATCard();//contructor --> initially has a $0 balance
		void debit( unsigned int amount);
		void credit( unsigned int amount);
		unsigned int getBalance() const;
};

#endif //WATCARD_H
