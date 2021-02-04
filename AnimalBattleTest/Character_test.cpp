#include "pch.h"
#include <gtest/gtest.h>
#include "Character.h"
#include "AnimalType.h"
#include <iostream>

// Make sure it is possible to add a weapon to the inventory
TEST(CharacterTest, AddItemToInventory) {
  Character testCharacter("TestCharacter", CAT);
  testCharacter.AddItemToCharacterInventory(STONE_KNIFE);
  EXPECT_EQ(testCharacter.FindSpecificItemInInventory(STONE_KNIFE).GetWeaponType(), STONE_KNIFE);
}

// Make sure the class method can find one item among many
TEST(CharacterTest, FindSpecificItemInInventory) {
	Character testCharacter("TestCharacter", CAT);
	testCharacter.AddItemToCharacterInventory(STONE_KNIFE);
	testCharacter.AddItemToCharacterInventory(WOODEN_BOW);
	EXPECT_EQ(testCharacter.FindSpecificItemInInventory(WOODEN_BOW).GetWeaponType(), WOODEN_BOW);
}

// Make sure that the character name is exposed in the class
TEST(CharacterTest, CharacterNameIsExpsed)
{
	Character testCharacter("TestCharacter", CAT);
	EXPECT_EQ(testCharacter.character_name, "TestCharacter");
}
