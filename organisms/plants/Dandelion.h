#ifndef PROJEKT1_DANDELION_H
#define PROJEKT1_DANDELION_H
#include "../Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(int x, int y);

	void action() override;
	void draw() override;
};



#endif //PROJEKT1_DANDELION_H
