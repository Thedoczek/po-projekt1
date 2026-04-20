#ifndef PROJEKT1_WORLD_H
#define PROJEKT1_WORLD_H
#include <vector>

#include "Organism.h"

class World {
public:
	World(int size_x, int size_y);

	void perform_turn();

	void draw_world();

	[[nodiscard]] Organism *get_occupant(Position pos) const;

	[[nodiscard]] int get_size_x() const;

	[[nodiscard]] int get_size_y() const;

	void add_spawn(Organism *spawn);

	void move_organism(Organism *organism, Position new_pos);

	~World();

private:
	std::vector<Organism *> queue;
	Organism **map;
	int size_x;
	int size_y;
};

#endif //PROJEKT1_WORLD_H
