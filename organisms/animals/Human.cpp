#include "Human.h"

Human::Human(World *world, const Position pos) : Animal(world, pos, 5, 4), ability_last_used() {
}

Organism *Human::spawn(const Position pos) const {
	return new Human(world, pos);
}
