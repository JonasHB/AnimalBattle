// Character.h
// Class used for instantiating a character with related methods and properties such as health.

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "AnimalType.h"
#include "Inventory.h"

class Character {
private:
	unsigned int health_;
	AnimalType characterAnimalType;	 // Every character must be a type of animal
	Inventory characterInventory;    // Every character has an inventory

public:
	std::string character_name;

	Character()
		: character_name("Noname"), characterAnimalType(NULL_ANIMAL), health_(10) {}

	Character(std::string myName, AnimalType myAnimalType)
		: character_name(myName), characterAnimalType(myAnimalType), health_(10) {}

	~Character() {};

	void AddItemToCharacterInventory(weapons item_to_add);
	Weapon GetSpecificItemInInventory(weapons weapon_to_be_found);
};

#endif //CHARACTER_H
