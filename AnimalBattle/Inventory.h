#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

#include <iostream>
#include <string>
#include "Weapon.h"

class Inventory {
	struct Item {
		Weapon this_weapon;
		Item *next;
	};
	Item *head;
	Item *cursor;
public:
	Inventory();
	~Inventory();
	void Add(weapons weapon_to_add);
	void ListInventory();
	std::list<Weapon> weapon_list;
	void StepCursor() { cursor = cursor->next; }
	void ResetCursor() { cursor = head; }
};

#endif //INVENTORY_H