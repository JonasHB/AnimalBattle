// Weapon.h
// Parent class for weapons. Responsible for keeping general weapon properties and methods.

#ifndef WEAPON_H
#define WEAPON_H

#include <list>
#include <string>

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
	weapons weapon_type;
	Weapon(weapons strWeaponType);
	Weapon();
	unsigned int get_range();
	unsigned int get_damage();
	std::string GetWeaponAsString();
};

class Bow : public Weapon{
public:
	weapons weapon_type;
	Bow(weapons strWeaponType);
	unsigned int arrows;
	void ChargeArrows(unsigned int amount_of_arrows_to_charge);
};
#endif //WEAPON_H
