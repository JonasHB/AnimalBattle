#include "Weapon.h"

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
}
std::string Weapon::get_weapon()
{
	if (m_WeaponType == WOODEN_BOW)
		return "Wooden bow";
	else if (m_WeaponType == STONE_KNIFE)
		return "Stone knife";
	else
		return "Undefined weapon";
}