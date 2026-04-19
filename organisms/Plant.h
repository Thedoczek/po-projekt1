#ifndef PROJEKT1_PLANT_H
#define PROJEKT1_PLANT_H
#include "../Organism.h"

class Plant : public Organism {
public:
	Plant(World* world, int pos_x, int pos_y, int strength);

	virtual void action();
	virtual void collision();
	virtual void draw() = 0;
};

#endif //PROJEKT1_PLANT_H
