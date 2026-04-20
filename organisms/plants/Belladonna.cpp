#include "Belladonna.h"

Belladonna::Belladonna(World *world, const Position pos) : Plant(world, pos, 99) {
}

Organism *Belladonna::spawn(const Position pos) const {
	return new Belladonna(world, pos);
}

Organism::DefendResult Belladonna::defend(Organism *attacker) {
	alive = false;
	return DefendResult::KILL_ATTACKER;
}
