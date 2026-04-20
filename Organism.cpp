#include "Organism.h"

#include <random>
#include <typeinfo>

Organism::Organism(
		World* const world, const Position pos, const int strength, const int initiative) :
		strength(strength),
		initiative(initiative),
		pos(pos),
		world(world) {
}

Position Organism::generate_neighbour_space(int radius) const {
	const int min_x = std::max(0, pos.x - radius);
	const int max_x = std::min(world->get_size_x() - 1, pos.x + radius);

	const int min_y = std::max(0, pos.y - radius);
	const int max_y = std::min(world->get_size_y() - 1, pos.y + radius);

	Position new_pos{};

	new_pos.x = min_x + static_cast<int>(random()) % (max_x - min_x + 1);
	new_pos.y = min_y + static_cast<int>(random()) % (max_y - min_y + 1);

	return new_pos;
}

Organism::DefendResult Organism::defend(Organism *attacker) {
	if (typeid(*attacker) == typeid(*this)) {

	}
}

Position Organism::get_pos() const {
	return pos;
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