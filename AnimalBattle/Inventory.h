// Inventory.h
// Class for containing and handling of character weapon inventory. Responsible for the content
// of the inventory.

#ifndef INVENTORY_H
#define INVENTORY_H

#include <list>
#include "Weapon.h"

class Inventory {
private:
	// As there is no need to perform any random access to the container a list is a
	// memory dynamic choice of container type.
	std::list<Weapon> weapon_list_;

public:
	Inventory() {};
	~Inventory();
	void Add(weapons weapon_to_add);
	const Weapon GetSpecificItemInInventory(weapons weapon_to_be_found);
	const int GetAmountOfItemsOfSpecificType(weapons weapon_to_be_found);
};

#endif //INVENTORY_H
