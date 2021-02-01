#ifndef ANIMALTYPE_H
#define ANIMALTYPE_H

#include <string>

enum animals { NULL_ANIMAL, CAT, DOG, GOAT, RABBIT };

class AnimalType {
public:
	animals m_strAnimalType;
	AnimalType(animals strAnimalType)
		: m_strAnimalType(strAnimalType) {}
};

#endif //ANIMALTYPE_H