#ifndef PROJEKT1_PLANT_H
#define PROJEKT1_PLANT_H
#include "../Organism.h"

class Plant : public Organism {
public:
	Plant(World* world, Position pos, int strength);

	void action() override;
	void draw() override = 0;
};

#endif //PROJEKT1_PLANT_H
