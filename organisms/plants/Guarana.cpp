#include "Guarana.h"

Guarana::Guarana(World *world, const Position pos) : Plant(world, pos, 0) {
}

Organism *Guarana::spawn(const Position pos) const {
	return new Guarana(world, pos);
}

Organism::DefendResult Guarana::defend(Organism *attacker) {
	alive = false;
	return DefendResult::GIVE_3_STRENGTH;
}
