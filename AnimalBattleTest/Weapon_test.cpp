#include "pch.h"
#include <gtest/gtest.h>
#include "Character.h"
#include "AnimalType.h"

// Default range is set as expected
TEST(WeaponTest, DefaultRangeAsExpected) {
	Weapon testWeapon;
	EXPECT_EQ(testWeapon.GetRange(), 0);
}

// Default damage is set as expected
TEST(WeaponTest, DefaultDamageAsExpected) {
	Weapon testWeapon;
	EXPECT_EQ(testWeapon.GetDamage(), 0);
}

// Bow range and damage as expected
TEST(WeaponTest, WeaponBowRangeAndDamageAsExpected) {
	Weapon testWeapon(WOODEN_BOW);
	EXPECT_EQ(testWeapon.GetRange(), 3);
	EXPECT_EQ(testWeapon.GetDamage(), 2);
}

// Knife range and damage as expected
TEST(WeaponTest, WeaponKnifeRangeAndDamageAsExpected) {
	Weapon testWeapon(STONE_KNIFE);
	EXPECT_EQ(testWeapon.GetRange(), 1);
	EXPECT_EQ(testWeapon.GetDamage(), 2);
}

// Bow range and damage as expected
TEST(WeaponTest, BowRangeAndDamageAsExpected) {
	Bow testBow(WOODEN_BOW);
	EXPECT_EQ(testBow.GetRange(), 3);
	EXPECT_EQ(testBow.GetDamage(), 2);
}

// Knife range and damage as expected
TEST(WeaponTest, KnifeRangeAndDamageAsExpected) {
	Weapon testKnife(STONE_KNIFE);
	EXPECT_EQ(testKnife.GetRange(), 1);
	EXPECT_EQ(testKnife.GetDamage(), 2);
}

// It should not be possible to create a Bow with the weapon type of knife
TEST(WeaponTest, BowIsNotAKnife) {
	bool got_invalid_argument = false;
	try {
		Bow testBow(STONE_KNIFE);
	}
	catch (std::invalid_argument) {
		// Expected outcome
		got_invalid_argument = true;
	}
	ASSERT_TRUE(got_invalid_argument);
}

// It should not be possible to create a Knife with the weapon type bow
TEST(WeaponTest, KnifeIsNotABow) {
	bool got_invalid_argument = false;
	try {
		Knife testKnife(WOODEN_BOW);
	}
	catch (std::invalid_argument) {
		// Expected outcome
		got_invalid_argument = true;
	}
	ASSERT_TRUE(got_invalid_argument);
}

// Charging a bow with arrows shall result in correct amount of arrows
TEST(WeaponTest, ChargingBowWithArrows) {
	Bow testBow(WOODEN_BOW);
	testBow.ChargeArrows(5);
	testBow.ChargeArrows(2);
	EXPECT_EQ(testBow.arrows, 7);
}

// The overriden method GetWeaponStats return the Bow class specific member arrows which the
// parent class does not
TEST(WeaponTest, OverridenMethodReturnWeaponStatsTakesArrowsInToAccount) {
	Knife testKnife(STONE_KNIFE);
	Bow testBow(WOODEN_BOW);

	testBow.ChargeArrows(5);

	weapon_properties stone_knife_properties = testKnife.GetWeaponStats();
	weapon_properties wooden_bow_properties = testBow.GetWeaponStats();

	EXPECT_EQ(stone_knife_properties.arrows, 0);
	EXPECT_EQ(wooden_bow_properties.arrows, 5);
}
