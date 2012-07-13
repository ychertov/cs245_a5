#ifndef __PRINTDATASTORE_H__
#define __PRINTDATASTORE_H__

/*
 *
 *	class that stores the print data
 *	
 *	setData: 	stores the data and prepares for printing 
 *	clear:		clears the data internally and makes it ready for new input,
 *             		called after it is printed
 *
 *
 */
class PrintDataStore {
	private:
		stl::pair<bool, char> state;
		stl::pair<bool, int> value1;
		stl::pair<bool, int> value2;
		
		void clear();
	
	public:
		void setState(char state);

		void setState(char state, int v1);

		void setState(char state, int v1, int v2);
	
};

friend std::iostream& operator<<( std::ostream& os, const PrintDataStore& pds );
#endif
