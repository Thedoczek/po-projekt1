#ifndef PROJEKT1_SHEEP_H
#define PROJEKT1_SHEEP_H
#include "../Animal.h"

class Sheep : public Animal {
public:
	Sheep(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	void draw() override;
};

#endif //PROJEKT1_SHEEP_H
