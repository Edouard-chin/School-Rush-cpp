/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:30:54 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 17:14:51 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.class.hpp"
#include "Squares.class.hpp"

#include "Monster.class.hpp"
#include "Player.class.hpp"
#include "Shoot.class.hpp"
#include "Wall.class.hpp"
#include "Ft_retro.hpp"
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
	Squares * c = new Squares(player, 5, 15);
	Squares * d = new Squares(monster, -5, 5);

	s.initGame();
	curses_init();
	for (int i = 0; i < 10; ++i)
		s.popSquares(new Squares(new Wall(), 0, i));
	s.pushSquares(c);
	s.pushSquares(d);
	for (int i = 0; i < 10; ++i)
		s.pushSquares(new Squares(new Wall(), 1, i));
	s.printAll();

	s.killSquares(s.getSquares());
	s.killSquares(s.getLastSquares());
	s.killSquares(c);
	s.printAll();
	s.clearScreen();
	s.printAll();
	s.generateNewWalls();
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

	curses_kill();

	return 0;
}
