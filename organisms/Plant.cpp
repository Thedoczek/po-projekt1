#include "Plant.h"

#include <random>

Plant::Plant(World *world, const Position pos, const int strength) : Organism(world, pos, strength, 0) {
}

void Plant::action() {
	if (random() % PLANT_SPREAD_FACTOR == 0 && pick_empty_neighbor(1) != pos) {
		world->add_spawn(spawn(pos));
	}
}
