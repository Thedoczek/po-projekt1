#include "Animal.h"

#include <random>

Animal::Animal(
	World *world, const Position pos, const int strength, const int initiative) : Organism(
	world, pos, strength, initiative) {
}

void Animal::action() {
	if (const Position new_pos = pick_neighbor(1); pos != new_pos) {
		// ReSharper disable once CppTooWideScopeInitStatement
		Organism *occupant = world->get_occupant(new_pos);

		switch (occupant ? occupant->defend(this) : DefendResult::MOVE_ATTACKER) {
			case DefendResult::MOVE_ATTACKER:
				pos = new_pos;
				break;
			case DefendResult::STOP_ATTACKER:
				break;
			case DefendResult::KILL_ATTACKER:
				alive = false;
				break;
			case DefendResult::GIVE_3_STRENGTH:
				strength += 3;
				pos = new_pos;
				break;
		}
	}

	if (alive) {
		age += 1;
	}
}
