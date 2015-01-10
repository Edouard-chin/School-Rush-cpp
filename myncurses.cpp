#include <iostream>
#include <ncurses.h>

#define Y_MAX 25
#define X_MAX 80

#define ESC 27
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define ENTER 10
#define SPACE 32

void		curses_init( void ) {

	initscr(); /* Init the screen */
	
	noecho(); /* No echo in the screen */
	curs_set(0); /* Hide the cursor */
	resizeterm(Y_MAX, X_MAX); /* Resize the ncurse grid */

	start_color(); 		/* Init color */
    init_pair(1, 1, 0); /* RED */
    init_pair(2, 2, 0); /* GREEN */
    init_pair(3, 3, 0); /* YELLOW */
    init_pair(4, 4, 0); /* BLUE */
    init_pair(5, 5, 0); /* MAGENTA */
    init_pair(6, 6, 0); /* CYAN */

	return;
}

void 		curses_print( int y, int x, char c, int color) {

	attron(COLOR_PAIR(color));
	mvprintw( y, x, "%c", c );
	attroff(COLOR_PAIR(color));
	refresh();

	return;
}

void 		curses_kill( void ) {

	clear();
	endwin();

	return;
}

/*int 	main() {


	curses_init();
	curses_print(5, 5, 'X', 5);
	getch();
	curses_kill();
	return 0;
}*/