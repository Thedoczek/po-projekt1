#include "Belladonna.h"

Belladonna::Belladonna(World *world, Position pos) : Plant(world, pos, 99) {
}

Organism *Belladonna::spawn(Position pos) const {
	return new Belladonna(world, pos);
}
