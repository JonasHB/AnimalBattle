#include "Character.h"

// Adding a weapon to the inventory
void Character::AddItemToCharacterInventory(weapons item_to_add) {
	characterInventory.Add(item_to_add);
}

// Search through the inventory and return the first weapon corresponding to the requested type
Weapon Character::GetSpecificItemInInventory(weapons weapon_to_be_found)
{
	return characterInventory.GetSpecificItemInInventory(weapon_to_be_found);
}
