#ifndef PROJEKT1_ANIMAL_H
#define PROJEKT1_ANIMAL_H
#include "../Organism.h"

class Animal : public Organism {
public:
	Animal(World* world, int pos_x, int pos_y, int strength, int initiative);

	void action() override;
	void collision() override;
	void draw() override = 0;
};

#endif //PROJEKT1_ANIMAL_H
