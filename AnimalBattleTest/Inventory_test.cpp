#include "pch.h"
#include <gtest/gtest.h>
#include "Character.h"
#include "AnimalType.h"

// Make sure it is possible to add a weapon to the inventory
TEST(InventoryTest, AddItemToInventory) {
	Inventory testInventory;
	testInventory.Add(WOODEN_BOW);
	EXPECT_EQ(testInventory.FindSpecificItemInInventory(WOODEN_BOW).GetWeaponType(), WOODEN_BOW);
}

// Make sure the class method can find one item among many
TEST(InventoryTest, FindSpecificItemInInventory) {
	Inventory testInventory;
	testInventory.Add(WOODEN_BOW);
	testInventory.Add(STONE_KNIFE);
	EXPECT_EQ(testInventory.FindSpecificItemInInventory(STONE_KNIFE).GetWeaponType(), STONE_KNIFE);
}
