#ifndef PROJEKT1_WORLD_H
#define PROJEKT1_WORLD_H
#include <vector>

#include "Organism.h"

class World {
public:
	World(int width, int height);

	void perform_turn();
	void draw_world();

	Organism* get_occupant(int pos_x, int pos_y) const;

	int get_size_x() const;
	int get_size_y() const;

	void add_survivor(Organism* organism);
	void add_killed(Organism* organism);

	void move_organism(Organism *organism, int new_x, int new_y);

	~World();
private:
	std::vector<Organism*> queue;
	std::vector<Organism*> next_queue;
	std::vector<Organism*> kill_queue;
	Organism** map;
	int size_x;
	int size_y;
};

#endif //PROJEKT1_WORLD_H
