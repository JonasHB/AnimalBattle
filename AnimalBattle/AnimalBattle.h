#include <string>

enum weapons { NULL_WEAPON, WOODEN_BOW, STONE_KNIFE };
enum animals { NULL_ANIMAL, CAT, DOG, GOAT, RABBIT };

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
};

class Inventory {
	struct Item {
		Weapon this_weapon;
		Item *next;
	};
	Item *head;
	Item *cursor;
public:
	Inventory();
	~Inventory();
	void add(weapons weapon_to_add);
	void list_inv();
	Weapon returnCursorItem();
	void stepCursor() { cursor = cursor->next; }
	void resetCursor() { cursor = head; }
};
