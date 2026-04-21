#include "World.h"
#include "Organism.h"
#include "organisms/animals/Wolf.h"
#include "organisms/animals/Sheep.h"
#include "organisms/animals/Fox.h"
#include "organisms/animals/Turtle.h"
#include "organisms/animals/Antelope.h"
#include "organisms/plants/Grass.h"
#include "organisms/plants/Dandelion.h"
#include "organisms/plants/Guarana.h"
#include "organisms/plants/Belladonna.h"
#include "organisms/plants/SosnowskyHogweed.h"

#include <algorithm>
#include <ncurses.h>

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

void World::draw_world() {
	clear();
	for (int y = 0; y < size_y + 2; ++y) {
		for (int x = 0; x < size_x + 2; ++x) {
			if (y == 0 || y == size_y + 1 || x == 0 || x == size_x + 1) {
				mvaddch(y, x, '#');
			}
		}
	}

	for (Organism const *org: queue) {
		if (org->is_alive()) {
			mvaddch(org->get_pos().y+1, org->get_pos().x+1, org->get_symbol());
		}
	}

	for (int i = 0; i < log.size(); ++i) {
		mvprintw(i, size_x + 4, "%s", log[i].c_str());
	}
	log.clear();

	refresh();
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

void World::write_to_log(const std::string &s) {
	log.push_back(s);
}

void World::populate_world() {
	for (int y = 0; y < size_y; ++y) {
		for (int x = 0; x < size_x; ++x) {
			Position const pos{x, y};

			if (get_occupant(pos) != nullptr) {
				continue;
			}

			if (random() % 25 == 0) {
				Organism *new_org = nullptr;

				switch (random() % 10) {
					case 0: new_org = new Wolf(this, pos);
						break;
					case 1: new_org = new Sheep(this, pos);
						break;
					case 2: new_org = new Fox(this, pos);
						break;
					case 3: new_org = new Turtle(this, pos);
						break;
					case 4: new_org = new Antelope(this, pos);
						break;
					case 5: new_org = new Grass(this, pos);
						break;
					case 6: new_org = new Dandelion(this, pos);
						break;
					case 7: new_org = new Guarana(this, pos);
						break;
					case 8: new_org = new Belladonna(this, pos);
						break;
					case 9: new_org = new SosnowskyHogweed(this, pos);
						break;
					default: break;
				}

				if (new_org) {
					add_spawn(new_org);
				}
			}
		}
	}
}

bool World::is_human_alive() const {
	for (const Organism *org: queue) {
		if (org->get_symbol() == 'H') {
			return org->is_alive();
		}
	}
	return false;
}

World::~World() {
	for (const Organism *elem: queue) {
		delete elem;
	}
	delete[] map;
}
