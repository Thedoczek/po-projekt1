#ifndef PROJEKT1_ANTELOPE_H
#define PROJEKT1_ANTELOPE_H
#include "../Animal.h"

class Antelope : public Animal {
public:
	Antelope(World* world, Position pos);

	void action() override;
	DefendResult defend(Organism* attacker) override;
	void draw() override;
};

#endif //PROJEKT1_ANTELOPE_H
