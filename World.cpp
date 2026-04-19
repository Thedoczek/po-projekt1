#include "World.h"

World::World(const int size_x, const int size_y) : size_x(size_x), size_y(size_y) {
	queue.clear();
	map = new Organism*[size_x*size_y]{};
}

bool World::isUnoccupied(const int pos_x, const int pos_y) {
	return map[pos_x*size_x + pos_y] != nullptr;
}

World::~World() {
	delete[] map;
}
