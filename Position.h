#ifndef PROJEKT1_POSITION_H
#define PROJEKT1_POSITION_H

struct Position {
	int x;
	int y;

	bool operator==(const Position &) const = default;
};

#endif //PROJEKT1_POSITION_H
