#ifndef PROJEKT1_HUMAN_H
#define PROJEKT1_HUMAN_H
#include "../Animal.h"

class Human : public Animal {
public:
	Human(World* world, Position pos);

	void action() override;
	DefendResult defend(Organism* attacker) override;

	void draw() override {}

private:
	int ability_last_used;
};

#endif //PROJEKT1_HUMAN_H
