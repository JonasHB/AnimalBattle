#include "Weapon.h"

Weapon::Weapon(weapons strWeaponType) :weapon_type(strWeaponType) {
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

Weapon::Weapon() {
	weapon_type = NULL_WEAPON;
}

unsigned int Weapon::get_range() {
	return range_;
}

unsigned int Weapon::get_damage() {
	return damage_;
}

std::string Weapon::GetWeaponAsString()
{
	if (weapon_type == WOODEN_BOW)
		return "Wooden bow";
	else if (weapon_type == STONE_KNIFE)
		return "Stone knife";
	else
		return "Undefined weapon";
}

Bow::Bow(weapons strWeaponType)
{
	weapon_type = strWeaponType;
	arrows = 0;
}

void Bow::ChargeArrows(unsigned int amount_of_arrows_to_charge)
{
	arrows = arrows + amount_of_arrows_to_charge;
}
