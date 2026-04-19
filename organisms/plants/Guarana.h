//
// Created by doczek on 19.04.2026.
//

#ifndef PROJEKT1_GUARANA_H
#define PROJEKT1_GUARANA_H
#include "../Plant.h"

class Guarana : public Plant {
public:
	Guarana(World* world, int pos_x, int pos_y);

	void collision() override;
	void draw() override;
};

#endif //PROJEKT1_GUARANA_H
