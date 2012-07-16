#ifndef __PRINTDATASTORE_H__
#define __PRINTDATASTORE_H__

/*
 *
 *	class that stores the print data
 *	
 *	setData: 	stores the data and prepares for printing 
 *	clear:		clears the data and makes it ready for new input,
 *
 *
 */

#include <utility>
#include <iostream>

class PrintDataStore {
	private:
		std::pair<bool, char> state;
		std::pair<bool, int> value1;
		std::pair<bool, int> value2;
		
	public:
		PrintDataStore();
		PrintDataStore(const PrintDataStore& pds);
		
		void setData(char st);

		void setData(char st, int v1);

		void setData(char st, int v1, int v2);
		
		void clear();
	
    		friend std::ostream &operator<<( std::ostream &os, const PrintDataStore& r );

};

extern std::ostream &operator<<( std::ostream &os, const PrintDataStore& r );

#endif
