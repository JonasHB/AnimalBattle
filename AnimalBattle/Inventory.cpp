#include "Inventory.h"

Inventory::Inventory() {
}
Inventory::~Inventory() {
	while (!weaponList.empty())
	{
		weaponList.pop_back();
	}
}
void Inventory::add(weapons weapon_to_add) {
	Weapon temp_weapon(weapon_to_add);
	weaponList.push_back(temp_weapon);
}
void Inventory::list_inv() {
	std::list<Weapon>::iterator it;
	for (it = weaponList.begin(); it != weaponList.end(); it++)
	{
		cout << "\t\t";
		cout << it->get_weapon();
		cout << std::endl;
	}
};