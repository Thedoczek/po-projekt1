#ifndef PROJEKT1_ORGANISM_H
#define PROJEKT1_ORGANISM_H

#include "World.h"

class Organism {
public:
	Organism(World* world, int pos_x, int pos_y, int strength, int initiative);
	virtual void action() = 0;
	virtual void collision(int pos_x, int pos_y) = 0;
	virtual void draw() = 0;

	virtual ~Organism() = default;

protected:
	int strength;
	int initiative;
	int age;
	int pos_x;
	int pos_y;
	World* world;
};

#endif //PROJEKT1_ORGANISM_H
