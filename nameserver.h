#ifndef __NAMESERVER_H__
#define __NAMESERVER_H__

#include "printer.h"

class VencdingMachine;

class NameServer {
	private:
		VendingMachine** machineList;
		//student machines
		void distribute();	
		/*
			logically distributs the students evenly across the vending machines in a round-robin fashion.
		*/

	public:
		NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
		/*
			calls distribute
			
		*/
		void VMregister( VendingMachine *vendingmachine );
		/*
			called by vending machines to register themselves	
		*/

		VendingMachine *getMachine( unsigned int id );
		/*
			if studentMachines[id] is null, assign a vending machine in a round robin fasion
			if not null, give next machine
		*/
		
		VendingMachine **getMachineList();
		/*
			return machineList
		*/
};

#endif
