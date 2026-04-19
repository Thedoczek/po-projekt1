#include "Plant.h"

Plant::Plant(World* world, int pos_x, int pos_y, int strength) :
Organism(world, pos_x, pos_y, strength, 0) {}