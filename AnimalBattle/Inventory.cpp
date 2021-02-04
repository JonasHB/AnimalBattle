#include "Inventory.h"

Inventory::Inventory() {
}

Inventory::~Inventory() {
	while (!weapon_list_.empty())
	{
		weapon_list_.pop_back();
	}
}

void Inventory::Add(weapons weapon_to_add) {
	Weapon temp_weapon(weapon_to_add);
	weapon_list_.push_back(temp_weapon);
}

void Inventory::ListInventory() {
	for (Weapon it : weapon_list_)
	{
		cout << "\t\t" << it.GetWeaponAsString() << endl;
	}
}

Weapon Inventory::FindSpecificItemInInventory(weapons weapon_to_be_found)
{
	for (Weapon it : weapon_list_)
	{
		if (it.GetWeaponType() == weapon_to_be_found)
			return it;
	}
	return NULL_WEAPON;
}
