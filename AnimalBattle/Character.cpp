#include "Character.h"

Character::~Character() {
}

void Character::AddItemToCharacterInventory(weapons item_to_add) {
	characterInventory.Add(item_to_add);
}

Weapon Character::FindSpecificItemInInventory(weapons weapon_to_be_found)
{
	return characterInventory.GetSpecificItemInInventory(weapon_to_be_found);
}
