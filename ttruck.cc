#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>					// numeric_limits
#include <cstdlib>					// exit

using namespace std;
#include "PRNG.h"
#include "debug.h"
#include "soda.h"					// YOUR INCLUDES GO IN THIS FILE

PRNG prng( getpid() );					// default seed of random-number generator


struct ConfigParms {
    unsigned int sodaCost;				// MSRP per bottle
    unsigned int numStudents;				// number of students to create
    unsigned int maxPurchases;				// maximum number of bottles a student purchases
    unsigned int numVendingMachines;			// number of vending machines
    unsigned int maxStockPerFlavour;			// maximum number of bottles of each flavour stocked
    unsigned int maxShippedPerFlavour;			// number of bottles of each flavour in a shipment
    unsigned int timeBetweenShipments;			// length of time between shipment pickup
}; // ConfigParms

void processConfigFile( const char *configFile, ConfigParms &cparms );

// Process the configuration file to set the parameters of the simulation.
void processConfigFile( const char *configFile, ConfigParms &cparms ) {
    enum { Parmnum = 7 };
    struct {
        const char *name;
        bool used;
        unsigned int *value;
    } static parms[Parmnum] = {
        { "SodaCost", false, &cparms.sodaCost },
        { "NumStudents", false, &cparms.numStudents },
        { "MaxPurchases", false, &cparms.maxPurchases },
        { "NumVendingMachines", false, &cparms.numVendingMachines },
        { "MaxStockPerFlavour", false, &cparms.maxStockPerFlavour },
        { "MaxShippedPerFlavour", false, &cparms.maxShippedPerFlavour },
        { "TimeBetweenShipments", false, &cparms.timeBetweenShipments },
    };
    string name;
    unsigned int value, cnt, posn;
    unsigned int numOfParm = 0;

    ifstream in( configFile );				// open configuration file for input
    if ( in.fail() ) {
        cerr << "Error: could not open input file \"" << configFile << "\"" << endl;
        exit( EXIT_FAILURE );
    } // if

    for ( cnt = 0 ; cnt < Parmnum; cnt += 1 ) {		// parameter names may appear in any order
	for ( ;; ) {
	    in >> name;
      if ( in.fail() ) goto fini;			// multi-level exit
	  if ( name.substr(0,1) != "#" ) break;
	    in.ignore( numeric_limits<int>::max(), '\n' ); // ignore remainder of line
	} // for
	for ( posn = 0; posn < Parmnum && name != parms[posn].name; posn += 1 ); // linear search
      if ( posn == Parmnum ) break;			// configuration not found ?
      if ( parms[posn].used ) break;			// duplicate configuration ?
	in >> value;
      if ( in.fail() ) break;				// no input
      if ( value < 1 ) break;				// error check
	in.ignore( numeric_limits<int>::max(), '\n' );	// ignore remainder of line
	numOfParm += 1;
	parms[posn].used = true;
	*parms[posn].value = value;
    } // for
  fini:
    if ( numOfParm != Parmnum ) {
	cerr << "Error: file \"" << configFile << "\" is corrupt." << endl;
	exit( EXIT_FAILURE );    
    } // if
} // processConfigFile


bool convert( int &val, char *buffer ) {		// convert C string to integer
    std::stringstream ss( buffer );			// connect stream and buffer
    ss >> dec >> val;					// convert integer from buffer
    return ! ss.fail() &&				// conversion successful ?
	// characters after conversion all blank ?
	string( buffer ).find_first_not_of( " ", ss.tellg() ) == string::npos;
} // convert

void usage( char *argv[] ) {
    cerr << "Usage: " << argv[0] << " [ config-file [ random-seed (1..N)] ]" << endl;
    exit( EXIT_FAILURE );
} // usage


int main( int argc, char *argv[] ) {
    const char *configFile = "soda.config";
    ConfigParms pm;
    int seed;						// seed for random number generator

    switch ( argc ) {
      case 3:
	if ( ! convert( seed, argv[2] ) || seed < 1 ) usage( argv ); // invalid ?
	prng.seed( seed );				// seed the random number generator
	// FALL THROUGH
      case 2:
	configFile = argv[1];
	// FALL THROUGH
      case 1:						// all defaults
	break;
      default:						// wrong number of options
	usage( argv );
    } // switch

    processConfigFile( configFile, pm );		// process configuration file
    Printer prt( pm.numStudents, pm.numVendingMachines );
    NameServer nameServer( prt, pm.numVendingMachines, pm.numStudents ); // manages vending machine names
	
	//Begin Test for Truck
	 BottlingPlant plant( prt, nameServer, pm.numVendingMachines, pm.maxShippedPerFlavour, pm.maxStockPerFlavour, pm.timeBetweenShipments );
	
	int tId = 1;
	
	Truck tTruck(prt, nameServer, plant, pm.numVendingMachines, pm.maxStockPerFlavour);

	VendingMachine(prt, nameServer, tId, pm.sodaCost, pm.maxStockPerFlavour );
		
        DEBUG(std::cout << "Created a Testing Truck" << std::endl);
        DEBUG(std::cout << "***Test1 getCargoVolume:"<< std::endl);
        DEBUG(std::cout << "\tInput\t" << "[1,1,1]" << std::endl);
	DEBUG(std::cout << "\tExpected Output\t" << "3" << std::endl);
	DEBUG(std::cout << "\tActual Output\t" << tTruck.getCargoVolume([1,1,1,1]) << std::endl);

	DEBUG(std::cout << "***Test2 getCargoVolume:"<< std::endl);
        DEBUG(std::cout << "\tInput\t" << "[0]" << std::endl);
	DEBUG(std::cout << "\tExpected Output\t" << "0" << std::endl);
	DEBUG(std::cout << "\tActual Output\t" << tTruck.getCargoVolume([]) << std::endl);
	
	DEBUG(std::cout << "***Test3 restock: (DEBUG flags within the function)"<< std::endl);	
}
//Testing for truck.cc
	//getCargoVolume function

/*
	Truck myTruck();//add params

	cout<< "\n*-->getCargoVolume test1*\nInput [1,1,1]\nExpected output = 3\nActual output = " << myTruck.getCargoVolume([1,1,1])<< endl;
	cout<< "\n*-->getCargoVolume test2*\nInput [0]\nExpected output = 0\nActual output = " << myTruck.getCargoVolume([0]) << endl;*/
