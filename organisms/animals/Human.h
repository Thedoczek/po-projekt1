#ifndef PROJEKT1_HUMAN_H
#define PROJEKT1_HUMAN_H
#include "../Animal.h"

class Human : public Animal {
public:
	Human(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	void action() override;

	DefendResult defend(Organism *attacker) override;

	[[nodiscard]] char get_symbol() const override {
		return 'H';
	}

private:
	int ability_last_used;
};

#endif //PROJEKT1_HUMAN_H
