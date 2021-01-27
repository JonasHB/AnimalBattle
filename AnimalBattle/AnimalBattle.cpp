#include <iostream>
#include <string>
#include "AnimalBattle.h"

using namespace std;

const unsigned char WOODEN_BOW_RANGE = 3;
const unsigned char WOODEN_BOW_DAMAGE = 2;
const unsigned char STONE_KNIFE_RANGE = 1;
const unsigned char STONE_KNIFE_DAMAGE = 2;





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
	head = NULL;
	cursor = NULL;
}
Inventory::~Inventory() {
	while (head != NULL) {
		Item *n = head->next;
		delete head;
		head = n;
	}
}
void Inventory::add(weapons weapon_to_add) {
	Item *n = new Item;
	Weapon temp_weapon(weapon_to_add);
	n->this_weapon = temp_weapon;
	n->next = head;
	head = n;
}
void Inventory::list_inv() {
	Item *n = head;
	while (n != NULL)
	{
		cout << printWeapon(n->this_weapon.m_WeaponType) << endl;

		n = n->next;
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
	charInventory.resetCursor();
	while (charInventory.returnCursorItem().m_WeaponType != NULL_WEAPON)
	{
		cout << "\t\t" << printWeapon(charInventory.returnCursorItem().m_WeaponType) << endl;
		charInventory.stepCursor();
	}
};
void Character::addItemToCharInv(weapons item_to_add) {
	charInventory.add(item_to_add);
};
void Character::listCharInv() {
	charInventory.list_inv();
};

int main()
{
	Character Bob("Bob", CAT);

	Bob.addItemToCharInv(STONE_KNIFE);
	Bob.addItemToCharInv(WOODEN_BOW);

	Character Nob;
	Bob.printDescription();
	Nob.printDescription();


	return 0;
}
