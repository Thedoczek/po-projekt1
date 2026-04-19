#ifndef PROJEKT1_DANDELION_H
#define PROJEKT1_DANDELION_H
#include "../Plant.h"

class Dandelion : public Plant {
public:
	Dandelion();

	void action() override;
	void draw() override;
};



#endif //PROJEKT1_DANDELION_H
