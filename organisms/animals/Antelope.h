#ifndef PROJEKT1_ANTELOPE_H
#define PROJEKT1_ANTELOPE_H
#include "../Animal.h"

class Antelope : public Animal {
public:
	Antelope();

	void action() override;
	void collision() override;
	void draw() override;
};

#endif //PROJEKT1_ANTELOPE_H
