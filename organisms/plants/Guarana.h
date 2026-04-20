//
// Created by doczek on 19.04.2026.
//

#ifndef PROJEKT1_GUARANA_H
#define PROJEKT1_GUARANA_H
#include "../Plant.h"

class Guarana : public Plant {
public:
	Guarana(World* world, Position pos);

	DefendResult defend(Organism* attacker) override;
	void draw() override;
};

#endif //PROJEKT1_GUARANA_H
