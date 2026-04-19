#ifndef PROJEKT1_ORGANISM_H
#define PROJEKT1_ORGANISM_H

#include "World.h"

class Organism {
public:
	virtual void action();
	virtual void collision();
	virtual void draw();
	virtual ~Organism();
private:
	int force;
	int initiative;
	int pos_x;
	int pos_y;
	World* world;
};

#endif //PROJEKT1_ORGANISM_H
