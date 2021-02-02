#include "AnimalBattle.h"
#include <cassert>

using namespace std;

int test1();
void DynamicAllocationOfAnimalWarriors();
void KnifeAndBowHaveDifferentRange();

int main()
{
	test1();
	DynamicAllocationOfAnimalWarriors();
	return 0;
}
int test1() {
	Character TestCharacter("TestCharacter", CAT);
	Character TestCharacter2;
	TestCharacter.addItemToCharInv(STONE_KNIFE);
	TestCharacter.addItemToCharInv(WOODEN_BOW);
	TestCharacter.printDescription();
	TestCharacter2.printDescription();
	return 0;
}
void DynamicAllocationOfAnimalWarriors()
{
	list<Character> ListOfAnimalWarriors;
	int amountOfWarriorsToBeCreated = 10000;

	for (int i = 0; i < amountOfWarriorsToBeCreated; i++)
	{
		Character TempWarrior("Warrior " + to_string(i), CAT);
		TempWarrior.addItemToCharInv(STONE_KNIFE);
		ListOfAnimalWarriors.push_back(TempWarrior);
	}
	assert(ListOfAnimalWarriors.size() == amountOfWarriorsToBeCreated);
	for (int i = 0; i < amountOfWarriorsToBeCreated; i++)
	{
		ListOfAnimalWarriors.pop_back();
	}
	assert(ListOfAnimalWarriors.size() == 0);
}

void KnifeAndBowHaveDifferentRange()
{
}
