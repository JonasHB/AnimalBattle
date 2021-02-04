#include "pch.h"
#include <gtest/gtest.h>
#include "Character.h"
#include "AnimalType.h"
#include <iostream>

// Default range is set as expected
TEST(WeaponTest, DefaultRangeAsExpected) {
	Weapon testWeapon;
	EXPECT_EQ(testWeapon.get_range(), 0);
}

// Default damage is set as expected
TEST(WeaponTest, DefaultDamageAsExpected) {
	Weapon testWeapon;
	EXPECT_EQ(testWeapon.get_damage(), 0);
}

// Bow range and damage as expected
TEST(WeaponTest, WeaponBowRangeAndDamageAsExpected) {
	Weapon testWeapon(WOODEN_BOW);
	EXPECT_EQ(testWeapon.get_range(), 3);
	EXPECT_EQ(testWeapon.get_damage(), 2);
}

// Knife range and damage as expected
TEST(WeaponTest, WeaponKnifeRangeAndDamageAsExpected) {
	Weapon testWeapon(STONE_KNIFE);
	EXPECT_EQ(testWeapon.get_range(), 1);
	EXPECT_EQ(testWeapon.get_damage(), 2);
}

// Bow range and damage as expected
TEST(WeaponTest, BowRangeAndDamageAsExpected) {
	Bow testBow(WOODEN_BOW);
	EXPECT_EQ(testBow.get_range(), 3);
	EXPECT_EQ(testBow.get_damage(), 2);
}

// Knife range and damage as expected
TEST(WeaponTest, KnifeRangeAndDamageAsExpected) {
	Weapon testKnife(STONE_KNIFE);
	EXPECT_EQ(testKnife.get_range(), 1);
	EXPECT_EQ(testKnife.get_damage(), 2);
}

// It should not be possible to create a Bow with the weapon type of knife
TEST(WeaponTest, BowIsNotAKnife) {
	bool got_invalid_argument = false;
	try {
		Bow testBow(STONE_KNIFE);
	}
	catch (invalid_argument) {
		// Expected outcome
		got_invalid_argument = true;
	}
	ASSERT_TRUE(got_invalid_argument);
}

// It should not be possible to create a Knife with the weapon type of bow
TEST(WeaponTest, KnifeIsNotABow) {
	bool got_invalid_argument = false;
	try {
		Knife testKnife(WOODEN_BOW);
	}
	catch (invalid_argument) {
		// Expected outcome
		got_invalid_argument = true;
	}
	ASSERT_TRUE(got_invalid_argument);
}

// Charging a bow with arrows result in correct amount of arrows
TEST(WeaponTest, ChargingBowWithArrows) {
	Bow testBow(WOODEN_BOW);
	testBow.ChargeArrows(5);
	EXPECT_EQ(testBow.arrows, 5);
}
