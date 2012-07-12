//This is the header file class.h (the interface for the class Student)

#include "student.h"

Student::Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id, unsigned int maxPurchases ) {
	/*
		**STUDENT CONTRUCTOR SPECIFICATIONS**
		-->id: [0, NumStudents)
		-->random number of bottles to purchase: [1, MaxPurchases]
		-->random favourite ﬂavour [0, 3]
		-->creating a WATCard (dynamically) with a $5 balance via the WATCardOfﬁce
		-->obtaining the location of a vending machine from the name server
	*/
}

bool Student::action() {
	/*
		*FALSE:-->When a student has purchased all the soda initially selected
		*TRUE:-->If the vending machine delivered a bottle of soda, the student drinks it and returns true.
	*/
}
