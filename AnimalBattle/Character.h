// Character.h
// Class used for instantiating a character with related methods and properties such as health.

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "AnimalType.h"
#include "Inventory.h"

class Character {
private:
	unsigned int health_;
	AnimalType characterAnimalType;
	Inventory characterInventory;

public:
	std::string character_name;

	Character()
		: character_name("Noname"), characterAnimalType(NULL_ANIMAL), health_(10) {}

	Character(std::string myName, AnimalType myAnimalType)
		: character_name(myName), characterAnimalType(myAnimalType), health_(10) {}

	~Character();

	void PrintDescription();
	void AddItemToCharacterInventory(weapons item_to_add);
	void ListCharacterInventory();
	Weapon FindSpecificItemInInventory(weapons weapon_to_be_found);
	std::string PrintAnimalType(animals myAnimalType);
};

#endif //CHARACTER_H
