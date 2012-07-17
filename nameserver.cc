#include "nameserver.h"
#include <assert.h>

//student machines
void NameServer::distribute() {
	for (unsigned int i = 0; i < numStudents; i++)
		studentMachine[i] = i%numVendingMachines;
/*
	logically distributs the students evenly across the vending machines in a round-robin fashion.
*/
}

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents ) : prt(prt), numVendingMachines(numVendingMachines), numStudents(numStudents) {
	distribute();
	machineList = new VendingMachine*[numVendingMachines];
	this->prt.print(KIND, START);
/*
	calls distribute	
*/
}

NameServer::~NameServer() {
	this->prt.print(KIND, FINISHED);
	delete machineList;
}

void NameServer::VMregister( VendingMachine *vendingmachine ) {
	assert(machineListLength+1 <= numVendingMachines);

	machineList[machineListLength] = vendingmachine;
	machineListLength++;
	this->prt.print(KIND, REGISTER, vendingmachine->getId());
/*
	called by vending machines to register themselves	
*/
}

VendingMachine *NameServer::getMachine( unsigned int id ) {
	studentMachine[id] = (studentMachine[id] + 1) % numVendingMachines; //set student next machine
	VendingMachine* machine = machineList[studentMachine[id]]; //return the new machine for the student
	this->prt.print(KIND, NEW_MACHINE, machine->getId());
	return machine;
}

VendingMachine **NameServer::getMachineList() {
	return machineList;
/*
	return machineList
*/
}


