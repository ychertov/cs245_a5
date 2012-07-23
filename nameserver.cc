#include "nameserver.h"
#include <assert.h>
#include "vendingmachine.h"
#include "debug.h"
#include <iostream>

//student machines
void NameServer::distribute() {
	for (unsigned int i = 0; i < numStudents; i++) {
		studentMachine[i] = i%numVendingMachines;
		DEBUG(std::cout << "student " << i << " assigned to machine index " << (i%numVendingMachines) << std::endl);	
	}
/*
	logically distributs the students evenly across the vending machines in a round-robin fashion.
*/
}

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents ) : prt(prt), numVendingMachines(numVendingMachines), numStudents(numStudents) {
	DEBUG(std::cout << "Calling Constructor" << std::endl);	
	distribute();
	machineListLength = 0;
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
	assert(machineListLength <= numVendingMachines);
	machineList[machineListLength] = vendingmachine;
	DEBUG(std::cout << "machine index " << machineListLength << " is machine id " << vendingmachine->getId() << std::endl);	
	machineListLength++;
	this->prt.print(KIND, REGISTER, vendingmachine->getId());
/*
	called by vending machines to register themselves	
*/
}

VendingMachine *NameServer::getMachine( unsigned int id ) {
	studentMachine[id] = (studentMachine[id] + 1) % numVendingMachines; //set student next machine
	VendingMachine* machine = machineList[studentMachine[id]]; //return the new machine for the student
	this->prt.print(KIND, NEW_MACHINE, id, machine->getId());
	return machine;
}

VendingMachine **NameServer::getMachineList() {
	return machineList;
/*
	return machineList
*/
}


