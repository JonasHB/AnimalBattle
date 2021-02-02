#include "AnimalBattle.h"
#include <cassert>

using namespace std;

int Test1();
void DynamicAllocationOfAnimalWarriors();
void KnifeAndBowHaveDifferentRange();

int main()
{
	Test1();
	DynamicAllocationOfAnimalWarriors();
	return 0;
}
int Test1() {
	Character testCharacter("TestCharacter", CAT);
	Character testCharacter2;
	testCharacter.AddItemToCharacterInventory(STONE_KNIFE);
	testCharacter.AddItemToCharacterInventory(WOODEN_BOW);
	testCharacter.PrintDescription();
	testCharacter2.PrintDescription();
	return 0;
}
void DynamicAllocationOfAnimalWarriors()
{
	list<Character> list_of_animal_warriors;
	int amount_of_warriors_to_be_created = 10000;

	for (int i = 0; i < amount_of_warriors_to_be_created; i++)
	{
		Character tempWarrior("Warrior " + to_string(i), CAT);
		tempWarrior.AddItemToCharacterInventory(STONE_KNIFE);
		list_of_animal_warriors.push_back(tempWarrior);
	}
	assert(list_of_animal_warriors.size() == amount_of_warriors_to_be_created);
	for (int i = 0; i < amount_of_warriors_to_be_created; i++)
	{
		list_of_animal_warriors.pop_back();
	}
	assert(list_of_animal_warriors.size() == 0);
}

void KnifeAndBowHaveDifferentRange()
{
}
