#ifndef PROJEKT1_TURTLE_H
#define PROJEKT1_TURTLE_H
#include "../Animal.h"

class Turtle : public Animal {
public:
	Turtle(int x, int y);

	void action() override;
	void collision() override;
	void draw() override;
};

#endif //PROJEKT1_TURTLE_H
