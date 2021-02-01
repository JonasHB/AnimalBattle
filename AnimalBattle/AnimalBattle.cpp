#include "AnimalBattle.h"

using namespace std;

int test1();
int DynamicAllocationOfAnimalWarriors();

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
int DynamicAllocationOfAnimalWarriors()
{
	list<Character> ListOfAnimalWarriors;
	for (int i = 0; i < 10; i++)
	{
		Character TempWarrior("Warrior " + to_string(i), CAT);
		TempWarrior.addItemToCharInv(STONE_KNIFE);
		ListOfAnimalWarriors.push_back(TempWarrior);
	}
	for (int i = 0; i < 10; i++)
	{
		ListOfAnimalWarriors.pop_back();
	}
	return 0;
}