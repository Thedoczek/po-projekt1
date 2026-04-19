#include "Organism.h"

Organism::Organism(World* world, int pos_x, int pos_y, int initiative, int strength) :
world(world),
pos_x(pos_x),
pos_y(pos_y),
initiative(initiative),
strength(strength) {}
