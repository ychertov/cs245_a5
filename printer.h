#ifndef __PRINTER_H__
#define __PRINTER_H__

#include "printdatastore.h"

class Printer {
	private:
		struct PrinterImpl;
		PrinterImpl &impl;
		unsigned int numStudents;
		unsigned int numVendingMachines;
		
		PrintDataStore& watOff;
		PrintDataStore& nameServer;
		PrintDataStore& truck;
		PrintDataStore& plant;
		Vector<PrintDataStore&> students;
		Vector<PrintDataStore&> machines;

		PrintDataStore& getPDS( Kind kind);
		PrintDataStore& getPDS( Kind kind, unsigned int id);
		Vector<PrintDataStore&> getPDSList();
		void prepPDS(PrintDataStore& pds);
	public:
		enum Kind { WATCardOffice, NameServer, Truck, BottlingPlant, Student, Vending };
		Printer( unsigned int numStudents, unsigned int numVendingMachines );
		~Printer();
		void print( Kind kind, char state );
		void print( Kind kind, char state, int value1 );
		void print( Kind kind, char state, int value1, int value2 );
		void print( Kind kind, unsigned int lid, char state );
		void print( Kind kind, unsigned int lid, char state, int value1);
		void print( Kind kind, unsigned int lid, char state, int value1, int value2 );
	
};
#endif
