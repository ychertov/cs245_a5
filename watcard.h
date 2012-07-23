//This is the header file watcard.h (the interface for the class WATCard

#ifndef WATCARD_H
#define WATCARD_H

class WATCard{//Manages the money associated with the card.
	private:
		unsigned int balance;
	public:
		WATCard();//contructor --> initially has a $0 balance
		void debit( unsigned int amount);
			/*
			-->Spends money from the WATcard
				*Preconditions:
					-balance [0,amount)
					(otherwise a call to standard error)
				*Postconditions:
					-balance [0, amount)
			*/
		void credit( unsigned int amount);
			/*
			-->Credits money on the WATcard
				*Preconditions:
					-N/A
				*Postconditions:
					-N/A
			*/
		unsigned int getBalance() const;
			/*
			-->Accessor function that gets the balance of the watcard
				*Preconditions:
					-N/A
				*Postconditions:
					-N/A
			*/
};

#endif //WATCARD_H
