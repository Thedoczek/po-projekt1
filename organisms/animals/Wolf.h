#ifndef PROJEKT1_WOLF_H
#define PROJEKT1_WOLF_H
#include "../Animal.h"

class Wolf : public Animal {
public:
	Wolf(int x, int y);
	void draw() override;
};

#endif //PROJEKT1_WOLF_H
