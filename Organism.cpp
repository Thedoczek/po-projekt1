#include "Organism.h"

Organism::Organism(
		World* const world, const int pos_x, const int pos_y, const int strength, const int initiative) :
		world(world),
		pos_x(pos_x),
		pos_y(pos_y),
		initiative(initiative),
		strength(strength) {}

int Organism::get_pos_x() const {
	return pos_x;
}
int Organism::get_pos_y() const {
	return pos_y;
}

int Organism::get_initiative() const {
	return initiative;
}

int Organism::get_age() const {
	return age;
}

bool Organism::is_alive() const {
	return alive;
}
