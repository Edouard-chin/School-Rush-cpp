/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:05:45 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 13:26:08 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.class.hpp"

Monster::Monster(void) : AEntity(Monster::MONSTER, 1, Monster::RED, 50, 50)
{

}

Monster::~Monster(void)
{

}

Monster::Monster (Monster const &monster) : AEntity(monster.getLetter(), monster.getVelocity(), monster.getColor(), monster.getMhp(), monster.getChp())
{

}

Monster const &Monster::operator=(Monster const &monster)
{
	this->setLetter(monster.getLetter());
	this->setVelocity(monster.getVelocity());
	this->setColor(monster.getColor());
	this->setMhp(monster.getMhp());
	this->setChp(monster.getChp());

	return monster;
}

char				Monster::die()
{
	std::cout << "AAARRGHHH" << std::endl;
	return ('*');
}