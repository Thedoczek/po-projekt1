#include "World.h"

#include <algorithm>

World::World(const int size_x, const int size_y) : size_x(size_x), size_y(size_y) {
	queue.clear();
	next_queue.clear();
	kill_queue.clear();
	map = new Organism*[size_x*size_y]{};
}

void World::perform_turn() {
	std::sort(queue.begin(), queue.end(), [](Organism* a, Organism* b) {
		if (a->get_initiative() == b->get_initiative()) {
			return a->get_age() > b->get_age();
		}
		return a->get_initiative() > b->get_initiative();
	});

	for (Organism* organism: queue) {
		if (organism->is_alive()) organism->action();
	}
	queue.clear();

	for (Organism const* organism: kill_queue) {
		delete organism;
	}
	kill_queue.clear();

	queue = next_queue;
	next_queue.clear();
}

Organism* World::get_occupant(const int pos_x, const int pos_y) const {
	return map[pos_x*size_y + pos_y];
}

int World::get_size_x() const {
	return size_x;
}
int World::get_size_y() const {
	return size_y;
}

void World::add_survivor(Organism *organism) {
	next_queue.push_back(organism);
}

void World::add_killed(Organism *organism) {
	kill_queue.push_back(organism);
}

void World::move_organism(Organism* organism, const int new_x, const int new_y) {
	map[new_x*size_y + new_y] = organism;
	map[organism->get_pos_x()*size_y + organism->get_pos_y()] = nullptr;
}

World::~World() {
	delete[] map;
}
