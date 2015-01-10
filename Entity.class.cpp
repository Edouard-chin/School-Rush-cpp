/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:37:30 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 15:11:25 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.class.hpp"

const	char		Entity::MONSTER = 'M';
const	char		Entity::PLAYER = 'P';
const	char		Entity::WALL = 'W';
const	char		Entity::SHOOT = 'S';
const	int			Entity::RED = 1;
const	int			Entity::GREEN = 2;
const	int			Entity::BLUE = 4;


Entity::Entity(char letter, int velocity, int color, int mhp, int chp) : _letter(letter), _velocity(velocity), _color(color), _mhp(mhp), _chp(chp)
{

}

Entity::~Entity(void)
{

}

Entity::Entity(const Entity &entity)
{

}

Entity &Entity::operator=(Entity const &entity)
{

}

char		Entity::getLetter(void) const
{
	return this->_letter;
}

void		Entity::setLetter(char letter)
{
	this->_letter = letter;
}

int			Entity::getVelocity(void) const
{
	return this->_velocity;
}

void		Entity::setVelocity(int velocity)
{
	this->_velocity = velocity;
}

int			Entity::getColor(void) const
{
	return this->_color;
}

void		Entity::setColor(int color)
{
	this->_color = color;
}

int			Entity::getMhp(void) const
{
	return this->_mhp;
}

void		Entity::setMhp(int mhp)
{
	this->_mhp = mhp;
}

int			Entity::getChp(void) const
{
	return this->_chp;
}

void		Entity::setChp(int chp)
{
	this->_chp = chp;
}
