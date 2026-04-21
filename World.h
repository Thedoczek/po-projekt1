#ifndef PROJEKT1_WORLD_H
#define PROJEKT1_WORLD_H
#include <string>
#include <vector>
#include "Position.h"


class Organism;

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

	void write_to_log(const std::string &s);

	void populate_world();

	[[nodiscard]] bool is_human_alive() const;

	~World();

private:
	std::vector<Organism *> queue;
	std::vector<std::string> log;
	Organism * *map;
	int size_x;
	int size_y;
};

#endif //PROJEKT1_WORLD_H
