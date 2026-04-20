#include "World.h"

#include <algorithm>

World::World(const int size_x, const int size_y) : size_x(size_x), size_y(size_y) {
	queue.clear();
	map = new Organism *[size_x * size_y]{};
}

void World::perform_turn() {
	// Sort queue by initiative
	std::ranges::sort(queue, [](const Organism *a, const Organism *b) {
		if (a->get_initiative() == b->get_initiative()) {
			return a->get_age() > b->get_age();
		}
		return a->get_initiative() > b->get_initiative();
	});

	// Perform actions
	const int initial_size = static_cast<int>(queue.size());
	for (int i = 0; i < initial_size; ++i) {
		if (queue[i]->is_alive()) queue[i]->action();
	}

	// Remove dead animals from the map
	for (int i = 0; i < size_x * size_y; ++i) {
		if (map[i] && !map[i]->is_alive()) {
			map[i] = nullptr;
		}
	}

	// Remove dead animals from the queue, removing memory
	std::erase_if(queue, [](const Organism *elem) {
		if (!elem->is_alive()) {
			delete elem;
			return true;
		}
		return false;
	});
	// I know these comments look like written by AI, I swear they're not
}

Organism *World::get_occupant(const Position pos) const {
	Organism *occupant = map[pos.x * size_y + pos.y];
	if (occupant && !occupant->is_alive()) {
		return nullptr;
	}

	return occupant;
}

int World::get_size_x() const {
	return size_x;
}

int World::get_size_y() const {
	return size_y;
}

void World::add_spawn(Organism *spawn) {
	queue.push_back(spawn);
	// ReSharper disable once CppUseStructuredBinding
	Position const pos = spawn->get_pos();
	map[pos.x * size_y + pos.y] = spawn;
}

// ReSharper disable once CppMemberFunctionMayBeConst
void World::move_organism(Organism *organism, const Position new_pos) {
	// ReSharper disable once CppUseStructuredBinding
	Position const old_pos = organism->get_pos();
	map[new_pos.x * size_y + new_pos.y] = organism;
	map[old_pos.x * size_y + old_pos.y] = nullptr;
}

World::~World() {
	for (const Organism *elem: queue) {
		delete elem;
	}
	delete[] map;
}
