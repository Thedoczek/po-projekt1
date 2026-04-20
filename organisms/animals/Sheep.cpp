#include "Sheep.h"

Sheep::Sheep(World *world, Position pos) : Animal(world, pos, 4, 4) {
}

Organism *Sheep::spawn(Position pos) const {
	return new Sheep(world, pos);
}
