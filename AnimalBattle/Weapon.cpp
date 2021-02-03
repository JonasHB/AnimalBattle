#include "Weapon.h"

// Determine range and damage of a weapon based on the weapon type
Weapon::Weapon(weapons strWeaponType) :weapon_type_(strWeaponType) {
	if (weapon_type_ == WOODEN_BOW)
	{
		range_ = WOODEN_BOW_RANGE;
		damage_ = WOODEN_BOW_DAMAGE;
	}
	else if (weapon_type_ == STONE_KNIFE)
	{
		range_ = STONE_KNIFE_RANGE;
		damage_ = STONE_KNIFE_DAMAGE;
	}
}

Weapon::Weapon() {
	weapon_type_ = NULL_WEAPON;
}

unsigned int Weapon::get_range() {
	return range_;
}

unsigned int Weapon::get_damage() {
	return damage_;
}

std::string Weapon::GetWeaponAsString()
{
	if (weapon_type_ == WOODEN_BOW)
		return "Wooden bow";
	else if (weapon_type_ == STONE_KNIFE)
		return "Stone knife";
	else
		return "Undefined weapon";
}

weapons Weapon::GetWeaponType()
{
	return weapon_type_;
}

Bow::Bow(weapons strWeaponType)
{
	if (strWeaponType > WOODEN_BOW)
	{
		throw std::invalid_argument("Weapon must be a bow in order to instantiate this class");
	}
	weapon_type_ = strWeaponType;
	arrows = 0;
}

void Bow::ChargeArrows(unsigned int amount_of_arrows_to_charge)
{
	arrows = arrows + amount_of_arrows_to_charge;
}

Knife::Knife(weapons strWeaponType)
{
	if (strWeaponType < STONE_KNIFE)
	{
		throw std::invalid_argument("Weapon must be a knife in order to instantiate this class");
	}
	weapon_type_ = strWeaponType;
}