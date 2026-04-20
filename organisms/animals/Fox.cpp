#include "Fox.h"

#include <typeinfo>

Fox::Fox(World *world, const Position pos) : Animal(world, pos, 3, 7) {
}

Organism *Fox::spawn(const Position pos) const {
	return new Fox(world, pos);
}

void Fox::action() {
	if (const Position new_pos = pick_neighbor(1); pos != new_pos) {
		// ReSharper disable once CppTooWideScopeInitStatement
		Organism *occupant = world->get_occupant(new_pos);

		if (typeid(*occupant) == typeid(*this) || occupant->get_strength() <= strength) {
			switch (occupant ? occupant->defend(this) : DefendResult::MOVE_ATTACKER) {
				case DefendResult::MOVE_ATTACKER:
					world->move_organism(this, new_pos);
					pos = new_pos;
					break;
				case DefendResult::STOP_ATTACKER:
					break;
				case DefendResult::KILL_ATTACKER:
					alive = false;
					break;
				case DefendResult::GIVE_3_STRENGTH:
					strength += 3;
					world->move_organism(this, new_pos);
					pos = new_pos;
					break;
			}
		}
	}

	if (alive) {
		age += 1;
	}
}
