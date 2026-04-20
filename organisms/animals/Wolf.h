#ifndef PROJEKT1_WOLF_H
#define PROJEKT1_WOLF_H
#include "../Animal.h"

class Wolf : public Animal {
public:
	Wolf(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	[[nodiscard]] char get_symbol() const override {
		return 'W';
	};
};

#endif //PROJEKT1_WOLF_H
