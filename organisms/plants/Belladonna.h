#ifndef PROJEKT1_BELLADONNA_H
#define PROJEKT1_BELLADONNA_H
#include "../Plant.h"

class Belladonna : public Plant {
public:
	Belladonna(World* world, int pos_x, int pos_y);

	void collision() override;
	void draw() override;
};

#endif //PROJEKT1_BELLADONNA_H
