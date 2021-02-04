#include "Character.h"

Character::~Character() {
}

void Character::PrintDescription() {
	std::cout << "Name: "
		<< character_name << std::endl
		<< "\tHealth: " << health_ << std::endl
		<< "\tAnimal type: " << PrintAnimalType(characterAnimalType.animal_type) << std::endl
		<< "\tInventory:" << std::endl;
	characterInventory.ListInventory();
}

void Character::AddItemToCharacterInventory(weapons item_to_add) {
	characterInventory.Add(item_to_add);
}

void Character::ListCharacterInventory() {
	characterInventory.ListInventory();
}

Weapon Character::FindSpecificItemInInventory(weapons weapon_to_be_found)
{
	return characterInventory.FindSpecificItemInInventory(weapon_to_be_found);
}

std::string Character::PrintAnimalType(animals myAnimalType) {
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
