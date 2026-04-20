#include "Antelope.h"

Antelope::Antelope(World *world, Position pos) : Animal(world, pos, 4, 4) {
}

Organism *Antelope::spawn(Position pos) const {
	return new Antelope(world, pos);
}
