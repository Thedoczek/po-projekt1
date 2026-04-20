#include "Dandelion.h"

Dandelion::Dandelion(World *world, Position pos) : Plant(world, pos, 0) {
}

Organism *Dandelion::spawn(Position pos) const {
	return new Dandelion(world, pos);
}
