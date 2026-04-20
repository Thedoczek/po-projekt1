#include "SosnowskyHogweed.h"

SosnowskyHogweed::SosnowskyHogweed(World *world, const Position pos) : Plant(world, pos, 10) {
}

Organism *SosnowskyHogweed::spawn(const Position pos) const {
	return new SosnowskyHogweed(world, pos);
}

void SosnowskyHogweed::action() {
	const int min_x = std::max(0, pos.x - 1);
	const int max_x = std::min(world->get_size_x() - 1, pos.x + 1);

	const int min_y = std::max(0, pos.y - 1);
	const int max_y = std::min(world->get_size_y() - 1, pos.y + 1);

	for (int x = min_x; x <= max_x; ++x) {
		for (int y = min_y; y <= max_y; ++y) {
			if (Organism *occupant = world->get_occupant(Position{x, y})) {
				occupant->kill();
			}
		}
	}
	
	Plant::action();
}

Organism::DefendResult SosnowskyHogweed::defend(Organism *attacker) {
	alive = false;
	return DefendResult::KILL_ATTACKER;
}
