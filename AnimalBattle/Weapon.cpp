#include "Weapon.h"

// Determine range and damage of a weapon based on the weapon type
Weapon::Weapon(weapons strWeaponType) :weapon_type(strWeaponType) {
	range_ = 0;
	damage_ = 0;
	DetermineWeaponParameters();
}

Weapon::Weapon() {
	range_ = 0;
	damage_ = 0;
	weapon_type = NULL_WEAPON;
}

// Get weapon range
const unsigned int Weapon::GetRange() {
	return range_;
}

// Get weapon damage
const unsigned int Weapon::GetDamage() {
	return damage_;
}

// Get weapon_type;
const weapons Weapon::GetWeaponType()
{
	return weapon_type;
}

// Get weapon properties. This method is overridden by child class
const weapon_properties Weapon::GetWeaponStats()
{
	return weapon_properties{ GetRange(), GetDamage(), weapon_type, 0};
}

// Determine range and damage of a weapon based on precompiled values
void Weapon::DetermineWeaponParameters()
{
	if (weapon_type == WOODEN_BOW)
	{
		range_ = WOODEN_BOW_RANGE;
		damage_ = WOODEN_BOW_DAMAGE;
	}
	else if (weapon_type == STONE_KNIFE)
	{
		range_ = STONE_KNIFE_RANGE;
		damage_ = STONE_KNIFE_DAMAGE;
	}
}

// Constructor for the Bow subclass. The constructor throws an exception if the weapon type is
// anything than a bow.
Bow::Bow(weapons strWeaponType)
{
	if (strWeaponType > WOODEN_BOW)
	{
		throw std::invalid_argument("Weapon must be a bow in order to instantiate this class");
	}
	weapon_type = strWeaponType;
	DetermineWeaponParameters();
	arrows = 0;
}

// In the Bow subclass it is possible to charge the bow with arrows.
void Bow::ChargeArrows(unsigned int amount_of_arrows_to_charge)
{
	arrows = arrows + amount_of_arrows_to_charge;
}

// This overridden method also return amount of arrows charged.
const weapon_properties Bow::GetWeaponStats()
{
	return weapon_properties{GetRange(), GetDamage(), weapon_type, arrows};
}

// Constructor for the Knife subclass.
Knife::Knife(weapons strWeaponType)
{
	if (strWeaponType < STONE_KNIFE)
	{
		throw std::invalid_argument("Weapon must be a knife in order to instantiate this class");
	}
	weapon_type = strWeaponType;
	DetermineWeaponParameters();
}
