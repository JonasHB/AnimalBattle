#include "Inventory.h"

// Getting rid of all weapons in the inventory. Really not necessary as the standard library deals
// with the deallocation of memory in its destructor. It is however a good reminder to be careful
// with data allocation.
Inventory::~Inventory() {
	while (!weapon_list_.empty())
	{
		weapon_list_.pop_back();
	}
}

// Adding weapon to the inventory
void Inventory::Add(weapons weapon_to_add) {
	Weapon temp_weapon(weapon_to_add);
	weapon_list_.push_back(temp_weapon);
}

// Return the first item in the inventory that corresponds input argument
const Weapon Inventory::GetSpecificItemInInventory(weapons weapon_to_be_found)
{
	for (Weapon it : weapon_list_)
	{
		if (it.weapon_type == weapon_to_be_found)
			return it;
	}
	return NULL_WEAPON;
}

// Return the amount of items in the inventory of a specified type
const int Inventory::GetAmountOfItemsOfSpecificType(weapons weapon_to_be_found)
{
	int counter = 0;
	for (Weapon it : weapon_list_)
	{
		if (it.weapon_type == weapon_to_be_found)
			counter++;
	}
	return counter;
}
