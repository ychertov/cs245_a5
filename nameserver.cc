#include "nameserver.h"

//student machines
void NameServer::distribute() {
/*
	logically distributs the students evenly across the vending machines in a round-robin fashion.
*/
}

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents ) {
/*
	calls distribute	
*/
}

void NameServer::VMregister( VendingMachine *vendingmachine ) {
/*
	called by vending machines to register themselves	
*/
}

VendingMachine *NameServer::getMachine( unsigned int id ) {
/*
	if studentMachines[id] is null, assign a vending machine in a round robin fasion
	if not null, give next machine
*/
}

VendingMachine **NameServer::getMachineList() {
/*
	return machineList
*/
}
