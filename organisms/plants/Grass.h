#ifndef PROJEKT1_GRASS_H
#define PROJEKT1_GRASS_H
#include "../Plant.h"

class Grass : public Plant {
public:
	Grass(World* world, int pos_x, int pos_y);
	void draw() override;
};

#endif //PROJEKT1_GRASS_H
