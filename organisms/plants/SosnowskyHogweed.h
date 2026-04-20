#ifndef PROJEKT1_SOSNOWSKY_HOGWEED_H
#define PROJEKT1_SOSNOWSKY_HOGWEED_H
#include "../Plant.h"

class SosnowskyHogweed : public Plant {
public:
	SosnowskyHogweed(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	void action() override;

	DefendResult defend(Organism *attacker) override;

	void draw() override;
};

#endif //PROJEKT1_SOSNOWSKY_HOGWEED_H
