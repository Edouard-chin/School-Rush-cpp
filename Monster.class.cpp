/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:05:45 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 16:48:14 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.class.hpp"

Monster::Monster(void) : Entity(Monster::MONSTER, 1, Monster::RED, 50, 50)
{

}

Monster::~Monster(void)
{

}

Monster::Monster (Monster const &monster) : Entity(monster.getLetter(), monster.getVelocity(), monster.getColor(), monster.getMhp(), monster.getChp())
{

}

Monster const &Monster::operator=(Monster const &monster)
{
	this->_letter = monster.getLetter();
	this->_velocity = monster.getVelocity();
	this->_color = monster.getColor();
	this->_mhp = monster.getMhp();
	this->_chp = monster.getChp();

	return monster;
}