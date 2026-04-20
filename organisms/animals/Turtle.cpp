#include "Turtle.h"

#include <random>
#include <typeinfo>

Turtle::Turtle(World *world, const Position pos) : Animal(world, pos, 2, 1) {
}

Organism *Turtle::spawn(const Position pos) const {
	return new Turtle(world, pos);
}

void Turtle::action() {
	if (random() % 4 == 0) {
		Animal::action();
	} else {
		age += 1;
	}
}

Organism::DefendResult Turtle::defend(Organism *attacker) {
	if (typeid(*attacker) == typeid(*this)) {
		if (Position const birth_pos = pick_empty_neighbor(1); birth_pos != pos) {
			world->add_spawn(spawn(birth_pos));
		}

		return DefendResult::STOP_ATTACKER;
	}

	if (attacker->get_strength() < 5) {
		return DefendResult::STOP_ATTACKER;
	}

	if (attacker->get_strength() > strength || (attacker->get_strength() == strength && attacker->get_age() > age)) {
		alive = false;
		return DefendResult::MOVE_ATTACKER;
	}

	return DefendResult::KILL_ATTACKER;
}
