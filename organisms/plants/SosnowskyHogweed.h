#ifndef PROJEKT1_SOSNOWSKY_HOGWEED_H
#define PROJEKT1_SOSNOWSKY_HOGWEED_H
#include "../Plant.h"

class SosnowskyHogweed : public Plant {
public:
	SosnowskyHogweed(World* world, int pos_x, int pos_y);

	void action() override;
	void collision() override;
	void draw() override;
};

#endif //PROJEKT1_SOSNOWSKY_HOGWEED_H
