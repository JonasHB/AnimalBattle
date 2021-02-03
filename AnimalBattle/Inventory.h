// Inventory.h
// Class for containing and handling of character weapon inventory. Responsible for adding, searching and listing weapons.

#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

#include <iostream>
#include <string>
#include "Weapon.h"

class Inventory {
private:
	std::list<Weapon> weapon_list_;

public:
	Inventory();
	~Inventory();
	void Add(weapons weapon_to_add);
	void ListInventory();
	Weapon FindSpecificItemInInventory(weapons weapon_to_be_found);
};

#endif //INVENTORY_H
