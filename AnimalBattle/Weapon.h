// Weapon.h
// Weapon related classes. The parent class Weapon is responsible for keeping general weapon
// properties and methods. The other classes in this file inherits the weapon class.

#ifndef WEAPON_H
#define WEAPON_H

#include <stdexcept>

const unsigned char WOODEN_BOW_RANGE = 3;
const unsigned char WOODEN_BOW_DAMAGE = 2;
const unsigned char STONE_KNIFE_RANGE = 1;
const unsigned char STONE_KNIFE_DAMAGE = 2;

enum weapons { NULL_WEAPON, WOODEN_BOW, STONE_KNIFE };

struct weapon_properties {
	const unsigned int range;
	const unsigned int damage;
	const weapons weapon_type;
	const unsigned int arrows;
};

class Weapon {
private:
	unsigned int range_;
	unsigned int damage_;

public:
	Weapon(weapons strWeaponType);
	Weapon();
	weapons weapon_type;
	const unsigned int GetRange();
	const unsigned int GetDamage();
	const weapons GetWeaponType();
	const virtual weapon_properties ReturnWeaponStats();
	virtual void DetermineWeaponParameters();
};

class Bow : public Weapon{
public:
	Bow(weapons strWeaponType);
	unsigned int arrows;
	void ChargeArrows(unsigned int amount_of_arrows_to_charge);
	const weapon_properties ReturnWeaponStats() override;
};

class Knife : public Weapon {
public:
	Knife(weapons strWeaponType);
};
#endif //WEAPON_H
