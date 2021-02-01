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
	unsigned int range;
	unsigned int damage;
public:
	weapons m_WeaponType;
	Weapon(weapons strWeaponType);
	Weapon();
	unsigned int get_range();
	unsigned int get_damage();
	std::string get_weapon();
};
#endif //WEAPON_H