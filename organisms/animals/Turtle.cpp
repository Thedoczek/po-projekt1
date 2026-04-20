#include "Turtle.h"

Turtle::Turtle(World *world, Position pos) : Animal(world, pos, 2, 1) {
}

Organism *Turtle::spawn(Position pos) const {
	return new Turtle(world, pos);
}
