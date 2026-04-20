#ifndef PROJEKT1_ANIMAL_H
#define PROJEKT1_ANIMAL_H
#include "../Organism.h"

class Animal : public Organism {
public:
	Animal(World *world, Position pos, int strength, int initiative);

	void action() override;

	DefendResult defend(Organism *attacker) override;

	[[nodiscard]] char get_symbol() const override = 0;
};

#endif //PROJEKT1_ANIMAL_H
