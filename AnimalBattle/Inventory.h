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
	void add(weapons weapon_to_add);
	void list_inv();
	Weapon returnCursorItem();
	std::list<Weapon> weaponList;
	void stepCursor() { cursor = cursor->next; }
	void resetCursor() { cursor = head; }
};

#endif //INVENTORY_H