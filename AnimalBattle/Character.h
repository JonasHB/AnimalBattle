#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "AnimalType.h"
#include "Inventory.h"

class Character {
private:
	std::string charName;
	AnimalType charAnimalType;
	unsigned int health;

	Inventory charInventory;
public:
	Character()
		: charName("Noname"), charAnimalType(NULL_ANIMAL), health(10) {}

	Character(std::string myName, AnimalType myAnimalType)
		: charName(myName), charAnimalType(myAnimalType), health(10) {}

	~Character();

	void printDescription();
	void addItemToCharInv(weapons item_to_add);
	void listCharInv();
};

std::string printAnimalType(animals myAnimalType);

#endif //CHARACTER_H