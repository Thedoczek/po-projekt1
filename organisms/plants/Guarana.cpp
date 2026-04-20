#include "Guarana.h"

Guarana::Guarana(World *world, Position pos) : Plant(world, pos, 0) {
}

Organism *Guarana::spawn(Position pos) const {
	return new Guarana(world, pos);
}
