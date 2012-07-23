#ifndef __NAMESERVER_H__
#define __NAMESERVER_H__

#include <map>
#include <utility>
#include "printer.h"

class VendingMachine;

class NameServer {
	private:
		static const Printer::Kind KIND = Printer::NameServer;

		static const char START = 'S';
		static const char REGISTER = 'R';
		static const char NEW_MACHINE = 'N';
		static const char FINISHED = 'F';

		Printer &prt;
		
		VendingMachine** machineList;
		unsigned int machineListLength;

		std::map<unsigned int, unsigned int> studentMachine;
		
		unsigned int numVendingMachines;
		unsigned int numStudents;
			
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

		~NameServer();
		
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
