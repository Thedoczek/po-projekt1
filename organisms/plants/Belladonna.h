#ifndef PROJEKT1_BELLADONNA_H
#define PROJEKT1_BELLADONNA_H
#include "../Plant.h"

class Belladonna : public Plant {
public:
	Belladonna(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	DefendResult defend(Organism *attacker) override;

	void draw() override;
};

#endif //PROJEKT1_BELLADONNA_H
