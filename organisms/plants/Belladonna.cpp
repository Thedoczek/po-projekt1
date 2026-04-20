#include "Belladonna.h"
#include "../../World.h"

Belladonna::Belladonna(World *world, const Position pos) : Plant(world, pos, 99) {
}

Organism *Belladonna::spawn(const Position pos) const {
	return new Belladonna(world, pos);
}

Organism::DefendResult Belladonna::defend(Organism *attacker) {
	alive = false;
	world->write_to_log("  Eat at " + std::to_string(pos.x) + ", " + std::to_string(pos.y));
	return DefendResult::KILL_ATTACKER;
}
