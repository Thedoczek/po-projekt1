#include "Dandelion.h"

Dandelion::Dandelion(World *world, const Position pos) : Plant(world, pos, 0) {
}

Organism *Dandelion::spawn(const Position pos) const {
	return new Dandelion(world, pos);
}

void Dandelion::action() {
	for (int i = 0; i < 3; ++i) {
		Plant::action();
	}
}
