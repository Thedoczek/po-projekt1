#ifndef PROJEKT1_ORGANISM_H
#define PROJEKT1_ORGANISM_H

#include "World.h"

class Organism {
public:
	virtual void action() = 0;
	virtual void collision() = 0;
	virtual void draw() = 0;

	virtual ~Organism() = default;

protected:
	int force;
	int initiative;
	int age;
	int pos_x;
	int pos_y;
	World* world;
};

#endif //PROJEKT1_ORGANISM_H
