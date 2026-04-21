#include <curses.h>
#include <ranges>

#include "World.h"
#include "organisms/animals/Human.h"

int main() {
	initscr();

	int size_x;
	int size_y;

	do {
		printw("Enter horizontal size (15-60): ");
		refresh();
		scanw("%d", &size_x);
	} while (size_x < 15 || size_x > 60);

	do {
		printw("Enter vertical size (10-20): ");
		refresh();
		scanw("%d", &size_y);
	} while (size_y < 10 || size_y > 20);

	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	clear();

	World world(size_x, size_y);
	auto *human = new Human(&world, Position{size_x / 2, size_y / 2});
	world.add_spawn(human);

	world.populate_world();

	while (world.is_human_alive()) {
		world.perform_turn();
	}

	world.draw_world();
	printw("You ded. Perhaps him skill issue");
	getch();
	endwin();

	return 0;
}
