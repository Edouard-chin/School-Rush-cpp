/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:30:54 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/11 15:30:51 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.class.hpp"
#include "Player.class.hpp"
#include "Shoot.class.hpp"
#include "Wall.class.hpp"
#include "Screen.class.hpp"
#include "Squares.class.hpp"


int main(int argc, char **argv)
{
	Screen *s;
	if (argc == 3)
		s = new Screen(std::atoi(argv[1]), std::atoi(argv[2]));
	else
		s = new Screen();

	s->initGame();
	while(s->newTurn() != Screen::ESC) {
	}
	s->printOutro();
	s->quitGame();
	delete s;

	return 0;
}
