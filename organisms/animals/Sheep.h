#ifndef PROJEKT1_SHEEP_H
#define PROJEKT1_SHEEP_H
#include "../Animal.h"

class Sheep : public Animal {
public:
	Sheep(World* world, int pos_x, int pos_y);
	void draw() override;
};

#endif //PROJEKT1_SHEEP_H
