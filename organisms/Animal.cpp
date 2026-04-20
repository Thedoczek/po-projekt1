#include "Animal.h"

#include <typeinfo>

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

	if (alive) {
		age += 1;
	}
}

Organism::DefendResult Animal::defend(Organism *attacker) {
	if (typeid(*attacker) == typeid(*this)) {
		if (Position const birth_pos = pick_empty_neighbor(1); birth_pos != pos) {
			world->add_spawn(spawn(birth_pos));
		}

		return DefendResult::STOP_ATTACKER;
	}

	if (attacker->get_strength() > strength || (attacker->get_strength() == strength && attacker->get_age() > age)) {
		alive = false;
		return DefendResult::MOVE_ATTACKER;
	}

	return DefendResult::KILL_ATTACKER;
}
