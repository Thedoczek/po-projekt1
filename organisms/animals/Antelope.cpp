#include "Antelope.h"
#include "../../World.h"

#include <typeinfo>
#include <random>

Antelope::Antelope(World *world, const Position pos) : Animal(world, pos, 4, 4) {
}

Organism *Antelope::spawn(const Position pos) const {
	return new Antelope(world, pos);
}

void Antelope::action() {
	if (const Position new_pos = pick_neighbor(2); pos != new_pos) {
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

Organism::DefendResult Antelope::defend(Organism *attacker) {
	if (typeid(*attacker) == typeid(*this)) {
		if (Position const birth_pos = pick_empty_neighbor(1); birth_pos != pos) {
			world->add_spawn(spawn(birth_pos));
			world->write_to_log("Birth at " + std::to_string(birth_pos.x) + ", " + std::to_string(birth_pos.y));
		}

		return DefendResult::STOP_ATTACKER;
	}
	
	world->write_to_log("Fight at " + std::to_string(pos.x) + ", " + std::to_string(pos.y));

	if (attacker->get_strength() > strength || (attacker->get_strength() == strength && attacker->get_age() > age)) {
		if (random() % 2 == 0) {
			if (const Position escape_pos = pick_empty_neighbor(1); escape_pos != pos) {
				world->move_organism(this, escape_pos);
				pos = escape_pos;
				return DefendResult::MOVE_ATTACKER;
			}
		}

		alive = false;
		return DefendResult::MOVE_ATTACKER;
	}

	return DefendResult::KILL_ATTACKER;
}
