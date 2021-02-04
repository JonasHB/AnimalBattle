// Weapon.h
// Weapon related classes. The parent class Weapon is responsible for keeping general weapon
// properties and methods. The other classes in this file inherits the weapon class.

#ifndef WEAPON_H
#define WEAPON_H

#include <list>
#include <string>
#include <stdexcept>
#include <iostream>

const unsigned char WOODEN_BOW_RANGE = 3;
const unsigned char WOODEN_BOW_DAMAGE = 2;
const unsigned char STONE_KNIFE_RANGE = 1;
const unsigned char STONE_KNIFE_DAMAGE = 2;

enum weapons { NULL_WEAPON, WOODEN_BOW, STONE_KNIFE };

class Weapon {
private:
	unsigned int range_;
	unsigned int damage_;

public:
	Weapon(weapons strWeaponType);
	Weapon();
	weapons weapon_type;
	unsigned int get_range();
	unsigned int get_damage();
	std::string GetWeaponAsString();
	weapons GetWeaponType();
	virtual void PrintWeaponStats();
	virtual void DetermineWeaponParameters();
};

class Bow : public Weapon{
private:

public:
	Bow(weapons strWeaponType);
	unsigned int arrows;
	void ChargeArrows(unsigned int amount_of_arrows_to_charge);
	void PrintWeaponStats() override;
};

class Knife : public Weapon {
private:

public:
	Knife(weapons strWeaponType);
};
#endif //WEAPON_H
