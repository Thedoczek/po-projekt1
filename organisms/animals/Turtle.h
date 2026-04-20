#ifndef PROJEKT1_TURTLE_H
#define PROJEKT1_TURTLE_H
#include "../Animal.h"

class Turtle : public Animal {
public:
	Turtle(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	void action() override;

	DefendResult defend(Organism *attacker) override;

	[[nodiscard]] char get_symbol() const override {
		return 'T';
	};
};

#endif //PROJEKT1_TURTLE_H
