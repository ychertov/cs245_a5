#ifndef __PRINTDATASTORE_H__
#define __PRINTDATASTORE_H__

class PrintDataStore {
//use pair instead of pointee
	private:
		stl::pair<bool, char> state;
		stl::pair<bool, int> value1;
		stl::pair<bool, int> value2;
	
	public:
		void setState(char state);

		void setValue1(int value);

		void setValue2(int value);
	
		void clear();
};

friend std::iostream& operator<<( std::ostream& os, const PrintDataStore& pds );
#endif
