#ifndef ANIMALTYPE_H
#define ANIMALTYPE_H

#include <string>

enum animals { NULL_ANIMAL, CAT, DOG, GOAT, RABBIT };

class AnimalType {
public:
	animals animal_type;
	AnimalType(animals animal_type)
		: animal_type(animal_type) {}
};

#endif //ANIMALTYPE_H