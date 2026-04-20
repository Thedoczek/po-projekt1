#include "SosnowskyHogweed.h"

SosnowskyHogweed::SosnowskyHogweed(World *world, Position pos) : Plant(world, pos, 10) {
}

Organism *SosnowskyHogweed::spawn(Position pos) const {
	return new SosnowskyHogweed(world, pos);
}
