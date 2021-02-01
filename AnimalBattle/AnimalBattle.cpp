#include <iostream>
#include "AnimalBattle.h"

using namespace std;


string printAnimalType(animals myAnimalType) {
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
string printWeapon(weapons myWeapon) {
	if (myWeapon == WOODEN_BOW)
		return "Wooden bow";
	else if (myWeapon == STONE_KNIFE)
		return "Stone knife";
	else
		return "Undefined weapon";
}

class AnimalType {
public:
	animals m_strAnimalType;
	AnimalType(animals strAnimalType)
		: m_strAnimalType(strAnimalType) {}
};

Weapon::Weapon(weapons strWeaponType) :m_WeaponType(strWeaponType) {
	if (m_WeaponType == WOODEN_BOW)
	{
		range = WOODEN_BOW_RANGE;
		damage = WOODEN_BOW_DAMAGE;
	}
	else if (m_WeaponType == STONE_KNIFE)
	{
		range = STONE_KNIFE_RANGE;
		damage = STONE_KNIFE_DAMAGE;
	}
}
Weapon::Weapon() {
	m_WeaponType = NULL_WEAPON;
};
unsigned int Weapon::get_range() {
	return range;
};
unsigned int Weapon::get_damage() {
	return damage;
};

class Armor {
};

Weapon null_Weapon;


Inventory::Inventory() {
}
Inventory::~Inventory() {
	while (!weaponList.empty())
	{
		weaponList.pop_back();
	}
}
void Inventory::add(weapons weapon_to_add) {
	Weapon temp_weapon(weapon_to_add);
	weaponList.push_back(temp_weapon);
}
void Inventory::list_inv() {
	list<Weapon>::iterator it;
	for (it = weaponList.begin(); it != weaponList.end(); it++)
	{
		cout << "\t\t" << printWeapon(it->m_WeaponType) << endl;
	}
};
Weapon Inventory::returnCursorItem() {
	if (cursor == NULL)
		return null_Weapon;
	else
		return cursor->this_weapon;
};

class Character {
private:
	string charName;
	AnimalType charAnimalType;
	unsigned int health;

	Inventory charInventory;
public:
	Character()
		: charName("Noname"), charAnimalType(NULL_ANIMAL), health(10) {}

	Character(string myName, AnimalType myAnimalType)
		: charName(myName), charAnimalType(myAnimalType), health(10) {}

	~Character();

	void printDescription();
	void addItemToCharInv(weapons item_to_add);
	void listCharInv();
};

Character::~Character() {
};
void Character::printDescription() {
	cout << "Name: "
		<< charName << endl
		<< "\tHealth: " << health << endl
		<< "\tAnimal type: " << printAnimalType(charAnimalType.m_strAnimalType) << endl
		<< "\tInventory:" << endl;
	charInventory.list_inv();
};
void Character::addItemToCharInv(weapons item_to_add) {
	charInventory.add(item_to_add);
};
void Character::listCharInv() {
	charInventory.list_inv();
};

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
		//ListOfAnimalWarriors.push_back(TempWarrior);
	}
	for (int i = 0; i < 10; i++)
	{
		//ListOfAnimalWarriors.pop_back();
	}
	return 0;
}