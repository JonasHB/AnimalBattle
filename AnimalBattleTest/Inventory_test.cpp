#include "pch.h"
#include <gtest/gtest.h>
#include "Character.h"
#include "AnimalType.h"

// Make sure it is possible to add a weapon to the inventory
TEST(InventoryTest, AddItemToInventory) {
	Inventory testInventory;
	testInventory.Add(WOODEN_BOW);
	EXPECT_EQ(testInventory.GetSpecificItemInInventory(WOODEN_BOW).weapon_type, WOODEN_BOW);
}

// Make sure the class method can find one item among many
TEST(InventoryTest, FindSpecificItemInInventory) {
	Inventory testInventory;
	testInventory.Add(WOODEN_BOW);
	testInventory.Add(STONE_KNIFE);
	EXPECT_EQ(testInventory.GetSpecificItemInInventory(STONE_KNIFE).weapon_type, STONE_KNIFE);
}

// It should be possible to return the amount of a specific weapon type in the inventory
TEST(InventoryTest, ReturnCorrectNumberOfWeaponsOfSpecifiedType) {
	Inventory testInventory;
	testInventory.Add(WOODEN_BOW);
	testInventory.Add(WOODEN_BOW);
	testInventory.Add(STONE_KNIFE);
	EXPECT_EQ(testInventory.GetAmountOfItemsOfSpecificType(WOODEN_BOW), 2);
	EXPECT_EQ(testInventory.GetAmountOfItemsOfSpecificType(STONE_KNIFE), 1);
}
