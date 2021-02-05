// Weapon.h
// Weapon related classes. The parent class Weapon is responsible for keeping general weapon
// properties and methods. The other classes in this file inherits the weapon class.

#ifndef WEAPON_H
#define WEAPON_H

const unsigned char WOODEN_BOW_RANGE = 3;
const unsigned char WOODEN_BOW_DAMAGE = 2;
const unsigned char STONE_KNIFE_RANGE = 1;
const unsigned char STONE_KNIFE_DAMAGE = 2;

enum weapons { NULL_WEAPON, WOODEN_BOW, STONE_KNIFE };

struct weapon_properties {
	unsigned int range;
	unsigned int damage;
	weapons weapon_type;
	unsigned int arrows;
};

class Weapon {
private:
	unsigned int range_;
	unsigned int damage_;

public:
	Weapon(weapons strWeaponType);
	Weapon();
	weapons weapon_type;
	unsigned int GetRange();
	unsigned int GetDamage();
	weapons GetWeaponType();
	virtual weapon_properties ReturnWeaponStats();
	virtual void DetermineWeaponParameters();
};

class Bow : public Weapon{
private:

public:
	Bow(weapons strWeaponType);
	unsigned int arrows;
	void ChargeArrows(unsigned int amount_of_arrows_to_charge);
	weapon_properties ReturnWeaponStats() override;
};

class Knife : public Weapon {
private:

public:
	Knife(weapons strWeaponType);
};
#endif //WEAPON_H
