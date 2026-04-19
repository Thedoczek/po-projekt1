#include "Organism.h"

Organism::Organism(
		World* const world, const int pos_x, const int pos_y, const int strength, const int initiative) :
		world(world),
		pos_x(pos_x),
		pos_y(pos_y),
		initiative(initiative),
		strength(strength)
{
	age = 0;
}
