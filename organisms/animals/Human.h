#ifndef PROJEKT1_HUMAN_H
#define PROJEKT1_HUMAN_H
#include "../Animal.h"

class Human : public Animal {
public:
	Human();

	void action() override;
	void collision() override;
	void draw() override;
};

#endif //PROJEKT1_HUMAN_H
