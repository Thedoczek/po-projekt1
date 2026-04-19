#include "Animal.h"

#include <random>

Animal::Animal(
	World* world, int pos_x, int pos_y, int strength, int initiative) :
Organism(world, pos_x, pos_y, strength, initiative) {}

void Animal::action() {
	const int new_x = static_cast<int>(random()%3) + pos_x - 1;
	const int new_y = static_cast<int>(random()%3) + pos_y - 1;

	if (!world->isUnoccupied(new_x, new_y)) {
		collision(new_x, new_y);
	}
}
