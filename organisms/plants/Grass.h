#ifndef PROJEKT1_GRASS_H
#define PROJEKT1_GRASS_H
#include "../Plant.h"

class Grass : public Plant {
public:
	Grass(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	[[nodiscard]] char get_symbol() const override {
		return ',';
	};
};

#endif //PROJEKT1_GRASS_H
