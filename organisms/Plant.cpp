#include "Plant.h"
#include "../World.h"

#include <random>

Plant::Plant(World *world, const Position pos, const int strength) : Organism(world, pos, strength, 0) {
}

void Plant::action() {
	if (random() % PLANT_SPREAD_FACTOR == 0) {
		if (Position const child_pos = pick_empty_neighbor(1); child_pos != pos) {
			world->add_spawn(spawn(child_pos));
			world->write_to_log(" Seed at " + std::to_string(child_pos.x) + ", " + std::to_string(child_pos.y));
		}
	}
}

Organism::DefendResult Plant::defend(Organism *attacker) {
	alive = false;
	world->write_to_log("  Eat at " + std::to_string(pos.x) + ", " + std::to_string(pos.y));
	return DefendResult::MOVE_ATTACKER;
}
