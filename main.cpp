/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:30:54 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 17:18:28 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.class.hpp"
#include "Player.class.hpp"
#include "Shoot.class.hpp"
#include "Wall.class.hpp"
#include "ft_retro.hpp"
#include "Screen.class.hpp"
#include "Squares.class.hpp"
#include <ncurses.h>
#include <unistd.h>

#define ESC 27
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define ENTER 10
#define SPACE 32

int main()
{

	Screen s;

	Monster * monster = new Monster();
	Player * player = new Player();
	// Shoot * shoot = new Shoot();
	// Wall * wall = new Wall();

	Squares * c = new Squares(player, 5, 15);
	Squares * d = new Squares(monster, -5, 5);
//	drawScreen();
	s.initGame();
	for (int i = 0; i < 10; ++i)
		s.popSquares(new Squares(new Wall(), 0, i));
	s.pushSquares(c);
	s.pushSquares(d);
	for (int i = 0; i < 10; ++i)
		s.pushSquares(new Squares(new Wall(), 1, i));
	s.printAll();

	s.killSquares(s.getSquares());
	s.killSquares(s.getLastSquares());
//	s.killSquares(c);
	s.printAll();
	s.clearScreen();
	s.printAll();
	s.generateNewWalls();

	std::cout << c;
	std::cout << d ;
	c->move();
	d->move(1, 14);

	std::cout << c ;
	std::cout << d ;
	c->move(5, 5);

	s.checkCollision();

	std::cout << c ;
	std::cout << d ;
	s.killSquares(c);

	s.printAll();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.generateNewMonster();
	s.printAll();

	

	return 0;
}

void drawScreen()
{
	// WINDOW *win;

	int 	row,col,x = 0,y = 0;
	int 	ch;
	char	player = 'X';
	int 	fire = 0, x_fire = -1, y_fire = -1;
	int 	megafire = 0, x_megafire = -1, y_megafire = -1;

	std::string s_megafire("------->");

	
	initscr();	/*init the screen*/
	start_color();
	resizeterm(25, 80); /* resize the ncurse grid */

    init_pair(1, 2, 0);
    init_pair(2, 1, 0);
    init_pair(3, 1, 0);

	noecho();
	curs_set(0); /*hide the cursor*/
	getmaxyx(stdscr,row,col); /*get max size of the screen*/
	//printw("row = %d and col = %d", row, col);
	//refresh();
	//getch();

	//mvprintw(row/2, i ,"%c", player);
	//i++;

	mvprintw(y, x ,"%c", player);

	while ( x <= col && x >= 0 && y <= row && y >= 0 ) {	
		
		ch = -1;
		timeout(100);
		ch = getch();
		clear();

		switch ( ch ) {

			case LEFT:
				x--;
				attron(COLOR_PAIR(1));
				mvprintw(y, x ,"%c", player);
				break;

			case RIGHT:
				x++;
				attron(COLOR_PAIR(1));
				mvprintw(y, x ,"%c", player);
				break;

			case UP:
				y--;
				attron(COLOR_PAIR(1));
				mvprintw(y, x ,"%c", player);
				break;

			case DOWN:
				y++;
				attron(COLOR_PAIR(1));
				mvprintw(y, x ,"%c", player);
				break;

			case ESC:
				x = -1;
				y = -1;
				break;

			case ENTER:
				fire = 1;
				break;

			case SPACE:
				megafire = 1;
				break;

			default:
				attron(COLOR_PAIR(1));
				mvprintw(y, x ,"%c", player);
				break;

		}

		//Test fire !
		if ( x_fire != -1 && x_fire <= col) {
			x_fire++;
			attron(COLOR_PAIR(2));
			mvprintw(y_fire, x_fire ,"%c", '-');
		}
		if ( fire == 1 ) {
			x_fire = x + 1;
			y_fire = y;
			fire = 0;
			attron(COLOR_PAIR(1));
			mvprintw(y, x ,"%c", player);
			attron(COLOR_PAIR(2));
			mvprintw(y_fire, x_fire ,"%c", '-');
		}

		//Test megafire !
		if ( x_megafire != -1 && (x_megafire + (int)s_megafire.size() + 1) <= col) {
			x_megafire++;
			attron(COLOR_PAIR(3));
			mvprintw(y_megafire, x_megafire ,"%s", s_megafire.c_str());
		}
		if ( megafire == 1 ) {
			x_megafire = x + 1;
			y_megafire = y;
			megafire = 0;
			attron(COLOR_PAIR(1));
			mvprintw(y, x ,"%c", player);
			attron(COLOR_PAIR(3));
			mvprintw(y_megafire, x_megafire ,"%s", s_megafire.c_str());
		}

		refresh();
	}

	clear();
	mvprintw(row/2,(col/2)-5,"%s","GAME OVER");
	refresh();
	timeout(-1);
	getch();
	endwin();
}
