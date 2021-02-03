// AnimalBattle.cpp
// Main file. The program AnimalBattle is a fantasy battle simulator. The purpose of the program
// is to serve as a porfolio showing a program created by JHB.

// Todo: Kommentera f�rdigt
// Todo: G�r n�got �t testerna, de kan inte ligga l�st i denna filen
// Todo: Kan man verkligen anv�nda klassen Bow som jag gjort. En inventory har en lista �ver Weapon, inte Bow. Det verkar ju dock funka.
// Todo: L�gg till n�got fr�n nyare version av C++

#include "AnimalBattle.h"
#include <cassert>

using namespace std;

int Test1();
void DynamicAllocationOfAnimalWarriors();
void KnifeAndBowHaveDifferentRange();
void UseSpecificBowFeature();
void KnifeMustBeAKnife();
void BowMustBeABow();

int main()
{
	Test1();
	DynamicAllocationOfAnimalWarriors();
	KnifeAndBowHaveDifferentRange();
	UseSpecificBowFeature();
	KnifeMustBeAKnife();
	BowMustBeABow();
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
	Character testCharacter("Test Character", CAT);
	testCharacter.AddItemToCharacterInventory(STONE_KNIFE);

	Character testCharacter2("Test Character 2", CAT);
	testCharacter2.AddItemToCharacterInventory(WOODEN_BOW);

	assert(testCharacter.FindSpecificItemInInventory(STONE_KNIFE).GetWeaponType() != testCharacter2.FindSpecificItemInInventory(WOODEN_BOW).GetWeaponType());
	assert(testCharacter.FindSpecificItemInInventory(STONE_KNIFE).get_range() != testCharacter2.FindSpecificItemInInventory(WOODEN_BOW).get_range());
}

void UseSpecificBowFeature()
{
	Bow testWeapon(WOODEN_BOW);
	testWeapon.ChargeArrows(5);
	assert(testWeapon.arrows == 5);
}

void KnifeMustBeAKnife()
{
	try {
		//Trying invalid class instantiation by trying to make a bow a knife
		Knife testWeapon(WOODEN_BOW);
	}
	catch (invalid_argument){
		// Expected outcome
	}
	catch (...) {
		assert(false);
	}
}

void BowMustBeABow()
{
	try {
		//Trying invalid class instantiation by trying to make a bow a knife
		Bow testWeapon(STONE_KNIFE);
	}
	catch (invalid_argument) {
		// Expected outcome
	}
	catch (...) {
		assert(false);
	}
}
