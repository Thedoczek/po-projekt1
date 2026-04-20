#ifndef PROJEKT1_ORGANISM_H
#define PROJEKT1_ORGANISM_H

#include "Position.h"
#include "World.h"

class Organism {
public:
	enum class DefendResult {
		MOVE_ATTACKER,
		STOP_ATTACKER,
		KILL_ATTACKER,
		GIVE_3_STRENGTH
	};

	Organism(World *world, Position pos, int strength, int initiative);

	[[nodiscard]] virtual Organism *spawn(Position pos) const = 0;

	virtual void action() = 0;

	virtual DefendResult defend(Organism *attacker) = 0;

	virtual void draw() = 0;

	[[nodiscard]] Position get_pos() const;

	[[nodiscard]] int get_strength() const;

	[[nodiscard]] int get_initiative() const;

	[[nodiscard]] int get_age() const;

	[[nodiscard]] bool is_alive() const;

	void kill();

	virtual ~Organism() = default;

protected:
	[[nodiscard]] Position pick_neighbor(int radius) const;

	[[nodiscard]] Position pick_empty_neighbor(int radius) const;

	bool alive = true;
	int strength;
	int initiative;
	int age = 0;
	Position pos;
	World *world;
};

#endif //PROJEKT1_ORGANISM_H
