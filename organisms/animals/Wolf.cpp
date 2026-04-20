#include "Wolf.h"

Wolf::Wolf(World *world, Position pos) : Animal(world, pos, 9, 5) {
}

Organism *Wolf::spawn(Position pos) const {
	return new Wolf(world, pos);
}
