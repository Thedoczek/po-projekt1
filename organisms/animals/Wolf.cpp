#include "Wolf.h"

Wolf::Wolf(World *world, const Position pos) : Animal(world, pos, 9, 5) {
}

Organism *Wolf::spawn(const Position pos) const {
	return new Wolf(world, pos);
}
