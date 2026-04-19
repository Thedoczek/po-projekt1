#ifndef PROJEKT1_WORLD_H
#define PROJEKT1_WORLD_H
#include <vector>

#include "Organism.h"

class World {
public:
	World(int width, int height);

	void perform_turn();
	void draw_world();

	bool isUnoccupied(int pos_x, int pos_y);

	~World();
private:
	std::vector<Organism*> queue;
	Organism** map;
	int size_x;
	int size_y;
};

#endif //PROJEKT1_WORLD_H
