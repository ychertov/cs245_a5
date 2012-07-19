#include "truck.h"
#include "flavours.h"
#include "vendingmachine.h"
Truck::Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant, unsigned int numVendingMachines, unsigned int maxStockPerFlavour ) : prt(prt), nameServer(nameServer), plant(plant), numVendingMachines(numVendingMachines), maxStockPerFlavour(maxStockPerFlavour) {
	prt.print(KIND, START);
}

unsigned int Truck::getCargoVolume(unsigned int cargo[]) {
	int totalSodaVolume = 0;
	for (int i = 0; i < FlavourInfo::FLAVOUR_LENGTH; i++)
		totalSodaVolume += cargo[i];
	return totalSodaVolume;
}

void Truck::restock(VendingMachine* vm, unsigned int cargo[]) {
	prt.print(KIND, BEGIN_DELIVERY, vm->getId(), getCargoVolume(cargo));
	unsigned int* inv = vm->inventory();

	for (int i = 0; i < FlavourInfo::FLAVOUR_LENGTH; i++) {
		if ((cargo[i] + inv[i]) <= maxStockPerFlavour) {
			inv[i] += cargo[i];
			cargo[i] = 0;
		} else {
			int amountAdded = maxStockPerFlavour - inv[i];
			inv[i] = maxStockPerFlavour;
			cargo[i] -= amountAdded;
		}
	}

	int totalUnfilled = 0;
	for (int i = 0; i < FlavourInfo::FLAVOUR_LENGTH; i++)
		totalUnfilled += maxStockPerFlavour - inv[i];

	if (totalUnfilled != 0)
		prt.print(KIND, UNSUCCESS_FILLING, vm->getId(), totalUnfilled);

	prt.print(KIND, END_DELIVERY, vm->getId(), getCargoVolume(cargo));
	vm->restocked();
}

void Truck::action() {
	unsigned int cargo[3];

	plant.getShipment(cargo);

	prt.print(KIND, PICKED_UP_SHIPMENT, getCargoVolume(cargo));

	VendingMachine** machineList = nameServer.getMachineList();

	for (unsigned int i = 0; i < numVendingMachines; i++) {
		restock(machineList[i], cargo);
	}

}

Truck::~Truck() {
	prt.print(KIND, FINISHED);
}
