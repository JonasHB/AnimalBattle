#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "AnimalType.h"
#include "Inventory.h"

class Character {
private:
	std::string character_name_;
	AnimalType characterAnimalType;
	unsigned int health_;

	Inventory characterInventory;
public:
	Character()
		: character_name_("Noname"), characterAnimalType(NULL_ANIMAL), health_(10) {}

	Character(std::string myName, AnimalType myAnimalType)
		: character_name_(myName), characterAnimalType(myAnimalType), health_(10) {}

	~Character();

	void PrintDescription();
	void AddItemToCharacterInventory(weapons item_to_add);
	void ListCharacterInventory();
};

std::string PrintAnimalType(animals myAnimalType);

#endif //CHARACTER_H