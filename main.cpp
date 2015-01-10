/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:30:54 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 15:31:48 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"
#include "Squares.hpp"

#include "Monster.class.hpp"
#include "Player.class.hpp"
#include "Shoot.class.hpp"
#include "Wall.class.hpp"

int main()
{

	Screen s;

	Monster monster;
	Player player;
	Shoot shoot;
	Wall wall;

	Squares * c = new Squares('c');
	Squares * d = new Squares('x', -5, 5);
	s.initGame();
	for (int i = 0; i < 10; ++i)
		s.popSquares(new Squares('r'));
	s.pushSquares(c);
	s.pushSquares(d);
	for (int i = 0; i < 10; ++i)
		s.pushSquares(new Squares('t'));
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

	return 0;
}