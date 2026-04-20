#include "Organism.h"

#include <random>
#include <typeinfo>

Organism::Organism(
	World *const world, const Position pos, const int strength, const int initiative) : strength(strength),
	initiative(initiative),
	pos(pos),
	world(world) {
}

Position Organism::pick_neighbor(const int radius) const {
	const int min_x = std::max(0, pos.x - radius);
	const int max_x = std::min(world->get_size_x() - 1, pos.x + radius);

	const int min_y = std::max(0, pos.y - radius);
	const int max_y = std::min(world->get_size_y() - 1, pos.y + radius);

	Position new_pos{};

	new_pos.x = min_x + static_cast<int>(random()) % (max_x - min_x + 1);
	new_pos.y = min_y + static_cast<int>(random()) % (max_y - min_y + 1);

	return new_pos;
}

Position Organism::pick_empty_neighbor(const int radius) const {
	const int min_x = std::max(0, pos.x - radius);
	const int max_x = std::min(world->get_size_x() - 1, pos.x + radius);

	const int min_y = std::max(0, pos.y - radius);
	const int max_y = std::min(world->get_size_y() - 1, pos.y + radius);

	std::vector<Position> free_positions;

	for (int x = min_x; x <= max_x; ++x) {
		for (int y = min_y; y <= max_y; ++y) {
			if (Position check_pos{x, y}; world->get_occupant(check_pos)) {
				free_positions.push_back(check_pos);
			}
		}
	}

	if (free_positions.empty()) {
		return pos;
	}

	return free_positions[random() % free_positions.size()];
}

Organism::DefendResult Organism::defend(Organism *attacker) {
	if (typeid(*attacker) == typeid(*this)) {
		if (Position const birth_pos = pick_empty_neighbor(1); birth_pos != pos) {
			world->add_spawn(spawn(birth_pos));
		}

		return DefendResult::STOP_ATTACKER;
	}

	if (attacker->get_strength() > strength || (attacker->get_strength() == strength && attacker->get_age() > age)) {
		alive = false;
		return DefendResult::MOVE_ATTACKER;
	} else {
		return DefendResult::KILL_ATTACKER;
	}
}

Position Organism::get_pos() const {
	return pos;
}

int Organism::get_strength() const {
	return strength;
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
