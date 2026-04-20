#ifndef PROJEKT1_FOX_H
#define PROJEKT1_FOX_H
#include "../Animal.h"

class Fox : public Animal {
public:
	Fox(World* world, Position pos);
	void action() override;
	void draw() override;
};

#endif //PROJEKT1_FOX_H
