#ifndef PROJEKT1_PLANT_H
#define PROJEKT1_PLANT_H
#include "../Organism.h"

#define PLANT_SPREAD_FACTOR 4	// One in N attempts are a success.

class Plant : public Organism {
public:
	Plant(World *world, Position pos, int strength);

	void action() override;

	void draw() override = 0;
};

#endif //PROJEKT1_PLANT_H
