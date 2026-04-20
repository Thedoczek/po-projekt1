#ifndef PROJEKT1_BELLADONNA_H
#define PROJEKT1_BELLADONNA_H
#include "../Plant.h"

class Belladonna : public Plant {
public:
	Belladonna(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	DefendResult defend(Organism *attacker) override;

	[[nodiscard]] char get_symbol() const override {
		return 'b';
	};
};

#endif //PROJEKT1_BELLADONNA_H
