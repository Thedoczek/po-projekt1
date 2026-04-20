#include "Grass.h"

Grass::Grass(World *world, Position pos) : Plant(world, pos, 0) {
}

Organism *Grass::spawn(Position pos) const {
	return new Grass(world, pos);
}
