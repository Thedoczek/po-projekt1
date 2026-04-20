#ifndef PROJEKT1_DANDELION_H
#define PROJEKT1_DANDELION_H
#include "../Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(World* world, Position pos);

	void action() override;
	void draw() override;
};



#endif //PROJEKT1_DANDELION_H
