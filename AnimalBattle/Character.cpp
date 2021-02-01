#include "Character.h"

Character::~Character() {
};
void Character::printDescription() {
	std::cout << "Name: "
		<< charName << std::endl
		<< "\tHealth: " << health << std::endl
		<< "\tAnimal type: " << printAnimalType(charAnimalType.m_strAnimalType) << std::endl
		<< "\tInventory:" << std::endl;
	charInventory.list_inv();
};
void Character::addItemToCharInv(weapons item_to_add) {
	charInventory.add(item_to_add);
};
void Character::listCharInv() {
	charInventory.list_inv();
};

std::string printAnimalType(animals myAnimalType) {
	if (myAnimalType == NULL_ANIMAL)
		return "Undetermined animal type";
	else if (myAnimalType == CAT)
		return "Cat";
	else if (myAnimalType == DOG)
		return "Dog";
	else if (myAnimalType == GOAT)
		return "Goat";
	else if (myAnimalType == RABBIT)
		return "Rabbit";
	else
		return "Undetermined animal type";
}