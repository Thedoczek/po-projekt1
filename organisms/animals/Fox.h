#ifndef PROJEKT1_FOX_H
#define PROJEKT1_FOX_H
#include "../Animal.h"

class Fox : public Animal {
public:
	Fox(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	void action() override;

	[[nodiscard]] char get_symbol() const override {
		return 'F';
	};
};

#endif //PROJEKT1_FOX_H
