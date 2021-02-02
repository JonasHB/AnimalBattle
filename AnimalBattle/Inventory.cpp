#include "Inventory.h"

Inventory::Inventory() {
}
Inventory::~Inventory() {
	while (!weapon_list.empty())
	{
		weapon_list.pop_back();
	}
}
void Inventory::Add(weapons weapon_to_add) {
	Weapon temp_weapon(weapon_to_add);
	weapon_list.push_back(temp_weapon);
}
void Inventory::ListInventory() {
	std::list<Weapon>::iterator it;
	for (it = weapon_list.begin(); it != weapon_list.end(); it++)
	{
		cout << "\t\t";
		cout << it->get_weapon();
		cout << std::endl;
	}
};