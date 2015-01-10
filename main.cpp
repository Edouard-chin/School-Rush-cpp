/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:30:54 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 20:44:55 by fbaudet-         ###   ########.fr       */
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
	Screen	s;

	s.initGame();
	while(s.newTurn() != Screen::ESC) {

	}

	return 0;
}
