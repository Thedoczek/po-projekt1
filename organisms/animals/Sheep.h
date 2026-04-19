#ifndef PROJEKT1_SHEEP_H
#define PROJEKT1_SHEEP_H
#include "../Animal.h"

class Sheep : public Animal {
public:
	Sheep(int x, int y);
	void draw() override;
};

#endif //PROJEKT1_SHEEP_H
