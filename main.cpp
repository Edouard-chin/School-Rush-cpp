/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:30:54 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 18:50:46 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.class.hpp"
#include "Player.class.hpp"
#include "Shoot.class.hpp"
#include "Wall.class.hpp"
#include "Screen.class.hpp"
#include "Squares.class.hpp"

#include <unistd.h>

int main()
{

	Screen s;
	Monster * monster = new Monster();
	Player * player = new Player();
	Squares * c = new Squares(player, 5, 15);
	Squares * d = new Squares(monster, -5, 5);

	s.initGame();
	for (int i = 0; i < 10; ++i)
		s.popSquares(new Squares(new Wall(), 0, i));
	s.pushSquares(c);
	s.pushSquares(d);
	for (int i = 0; i < 10; ++i)
		s.pushSquares(new Squares(new Wall(), 1, i));

	int ret = 0;

	while(ret != Screen::ESC){
		ret = s.curses_input();
		s.printAll();
	}

	return 0;
}
