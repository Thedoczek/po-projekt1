#include "Sheep.h"
#include "../../World.h"

Sheep::Sheep(World *world, const Position pos) : Animal(world, pos, 4, 4) {
}

Organism *Sheep::spawn(const Position pos) const {
	return new Sheep(world, pos);
}
