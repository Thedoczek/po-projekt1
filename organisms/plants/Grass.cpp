#include "Grass.h"

Grass::Grass(World *world, const Position pos) : Plant(world, pos, 0) {
}

Organism *Grass::spawn(const Position pos) const {
	return new Grass(world, pos);
}
