#ifndef PROJEKT1_WOLF_H
#define PROJEKT1_WOLF_H
#include "../Animal.h"

class Wolf : public Animal {
public:
	Wolf(World* world, int pos_x, int pos_y);
	void draw() override;
};

#endif //PROJEKT1_WOLF_H
