#ifndef PROJEKT1_FOX_H
#define PROJEKT1_FOX_H
#include "../Animal.h"

class Fox : public Animal {
public:
	Fox(World* world, int pos_x, int pos_y);
	void action() override;
	void draw() override;
};

#endif //PROJEKT1_FOX_H
