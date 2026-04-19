#ifndef PROJEKT1_ORGANISM_H
#define PROJEKT1_ORGANISM_H

#include "World.h"

class Organism {
public:
	enum class DefendResult {
		MOVE_ATTACKER,
		STOP_ATTACKER,
		KILL_ATTACKER,
		GIVE_3_STRENGTH
	};

	Organism(World* world, int pos_x, int pos_y, int strength, int initiative);
	virtual void action() = 0;
	virtual void attack(int pos_x, int pos_y) = 0;
	virtual DefendResult defend(Organism* attacker) = 0;
	virtual void draw() = 0;

	int get_initiative() const;
	int get_age() const;
	bool is_alive() const;

	virtual ~Organism() = default;

protected:
	bool alive = true;
	int strength;
	int initiative;
	int age = 0;
	int pos_x;
	int pos_y;
	World* world;
};

#endif //PROJEKT1_ORGANISM_H
