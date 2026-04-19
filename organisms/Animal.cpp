#include "Animal.h"

#include <random>

Animal::Animal(
	World* world, int pos_x, int pos_y, int strength, int initiative) :
Organism(world, pos_x, pos_y, strength, initiative) {}

void Animal::action() {
	int new_x, new_y;
	do {
		new_x = static_cast<int>(random()%3) + pos_x - 1;
	} while (new_x < 0 || new_x > world->get_size_x());
	do {
		new_y = static_cast<int>(random()%3) + pos_x - 1;
	} while (new_y < 0 || new_y > world->get_size_y());

	if (new_x != pos_x || new_y != pos_y) {
		// ReSharper disable once CppTooWideScopeInitStatement
		Organism* occupant = world->get_occupant(new_x, new_y);

		switch (occupant ? occupant->defend(this) : DefendResult::MOVE_ATTACKER) {
			case DefendResult::MOVE_ATTACKER:
				pos_x = new_x;
				pos_y = new_y;
			case DefendResult::STOP_ATTACKER:
				break;
			case DefendResult::KILL_ATTACKER:
				alive = false;
			case DefendResult::GIVE_3_STRENGTH:
				strength += 3;
				pos_x = new_x;
				pos_y = new_y;
		}
	}

	if (alive) {
		age += 1;
		world->add_survivor(this);
	} else
		world->add_killed(this);
	}
}
