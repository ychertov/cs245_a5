//This is the header file class.h (the interface for the class Student)

#ifndef STUDENT_H
#define STUDENT_H

#include "printer.h"
#include "nameserver.h"
#include "watcardoffice.h"
#include "flavours.h"
#include "watcard.h"
#include "vendingmachine.h"

class Student {//A Student’s function is to buy some of their favourite soda from a vending machine.
	private:
		Printer& prt;
		NameServer& nameServer;
		WATCardOffice& cardOffice;
		unsigned int id;
		unsigned int purchasesRemaining;
		Flavours faveFlave;
		WATCard* watcard;
		VendingMachine* currentMachine;
	
	public:
		Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id, unsigned int maxPurchases );
		/*
			**STUDENT CONTRUCTOR SPECIFICATIONS**
			-->id: [0, NumStudents)
			-->random number of bottles to purchase: [1, MaxPurchases]
			-->random favourite ﬂavour [0, 3]
			-->creating a WATCard (dynamically) with a $5 balance via the WATCardOfﬁce
			-->obtaining the location of a vending machine from the name server
		*/

		bool action();//the way a students behaviour is defined.
		/*
			*FALSE:-->When a student has purchased all the soda initially selected
			*TRUE:-->If the vending machine delivered a bottle of soda, the student drinks it and returns true.
		*/
};

#endif
//Melissa Tardibuono
