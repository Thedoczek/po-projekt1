#include "Guarana.h"
#include "../../World.h"

Guarana::Guarana(World *world, const Position pos) : Plant(world, pos, 0) {
}

Organism *Guarana::spawn(const Position pos) const {
	return new Guarana(world, pos);
}

Organism::DefendResult Guarana::defend(Organism *attacker) {
	alive = false;
	world->write_to_log("  Eat at " + std::to_string(pos.x) + ", " + std::to_string(pos.y));
	return DefendResult::GIVE_3_STRENGTH;
}
