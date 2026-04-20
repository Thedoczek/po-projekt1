#ifndef PROJEKT1_DANDELION_H
#define PROJEKT1_DANDELION_H
#include "../Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(World *world, Position pos);

	[[nodiscard]] Organism *spawn(Position pos) const override;

	void action() override;

	[[nodiscard]] char get_symbol() const override {
		return 'd';
	};
};


#endif //PROJEKT1_DANDELION_H
