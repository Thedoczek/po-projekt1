#ifndef PROJEKT1_WOLF_H
#define PROJEKT1_WOLF_H
#include "../Animal.h"

class Wolf : public Animal {
public:
	Wolf(World* world, Position pos);
	void draw() override;
};

#endif //PROJEKT1_WOLF_H
