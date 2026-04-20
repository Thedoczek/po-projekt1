#include "Fox.h"

Fox::Fox(World *world, Position pos) : Animal(world, pos, 3, 7) {
}

Organism *Fox::spawn(Position pos) const {
	return new Fox(world, pos);
}
