#include <string>
#include <list>

const unsigned char WOODEN_BOW_RANGE = 3;
const unsigned char WOODEN_BOW_DAMAGE = 2;
const unsigned char STONE_KNIFE_RANGE = 1;
const unsigned char STONE_KNIFE_DAMAGE = 2;

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
	std::list<Weapon> weaponList;
	void stepCursor() { cursor = cursor->next; }
	void resetCursor() { cursor = head; }
};
