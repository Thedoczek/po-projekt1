#ifndef PROJEKT1_BELLADONNA_H
#define PROJEKT1_BELLADONNA_H
#include "../Plant.h"

class Belladonna : public Plant {
public:
	Belladonna();

	void collision() override;
	void draw() override;
};

#endif //PROJEKT1_BELLADONNA_H
