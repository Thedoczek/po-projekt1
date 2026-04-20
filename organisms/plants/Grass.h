#ifndef PROJEKT1_GRASS_H
#define PROJEKT1_GRASS_H
#include "../Plant.h"

class Grass : public Plant {
public:
	Grass(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	void draw() override;
};

#endif //PROJEKT1_GRASS_H
