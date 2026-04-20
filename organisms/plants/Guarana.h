#ifndef PROJEKT1_GUARANA_H
#define PROJEKT1_GUARANA_H
#include "../Plant.h"

class Guarana : public Plant {
public:
	Guarana(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	DefendResult defend(Organism *attacker) override;

	[[nodiscard]] char get_symbol() const override {
		return 'g';
	};
};

#endif //PROJEKT1_GUARANA_H
