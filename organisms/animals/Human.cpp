#include "Human.h"

Human::Human(World *world, Position pos) : Animal(world, pos, 5, 4), ability_last_used() {
}

Organism *Human::spawn(Position pos) const {
	return new Human(world, pos);
}
