#include "Human.h"

#include <curses.h>

#include "../../World.h"

Human::Human(World *world, const Position pos) : Animal(world, pos, 5, 4), ability_last_used() {
}

Organism *Human::spawn(const Position pos) const {
	return new Human(world, pos);
}

void Human::action() {
	world->draw_world();

	Position new_pos = pos;

	bool input_valid = false;
	while (!input_valid) {
		switch (getch()) {
			case 'w':
				if (pos.y > 0) {
					new_pos.y -= 1;
					input_valid = true;
				}
				break;
			case 's':
				if (pos.y < world->get_size_y() - 1) {
					new_pos.y += 1;
					input_valid = true;
				}
				break;
			case 'a':
				if (pos.x > 0) {
					new_pos.x -= 1;
					input_valid = true;
				}
				break;
			case 'd':
				if (pos.x < world->get_size_x() - 1) {
					new_pos.x += 1;
					input_valid = true;
				}
				break;
			case 'q':
				if (age - ability_last_used >= 10) {
					ability_last_used = age;
					world->write_to_log("Ability active");
				}
				break;
			default:
				break;
		}
	}

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

	if (alive) {
		age += 1;
	}
}

Organism::DefendResult Human::defend(Organism *attacker) {
	return Animal::defend(attacker);
}
