/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:37:30 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 13:23:44 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AEntity.class.hpp"

const	char		AEntity::MONSTER = 'X';
const	char		AEntity::PLAYER = '>';
const	char		AEntity::WALL = '#';
const	char		AEntity::SHOOT = '-';
const	int			AEntity::RED = 1;
const	int			AEntity::GREEN = 2;
const	int			AEntity::BLUE = 4;

AEntity::AEntity() : _letter('-'), _velocity(0), _color(0), _mhp(0), _chp(0)
{

}

AEntity::AEntity(char letter, int velocity, int color, int mhp, int chp) : _letter(letter), _velocity(velocity), _color(color), _mhp(mhp), _chp(chp)
{

}

AEntity::~AEntity(void)
{

}

AEntity::AEntity(const AEntity &entity) : _letter(entity.getLetter()), _velocity(entity.getVelocity()), _color(entity.getColor()), _mhp(entity.getMhp()), _chp(entity.getChp())
{

}

AEntity const &AEntity::operator=(AEntity const &entity)
{
	this->setLetter(entity.getLetter());
	this->setVelocity(entity.getVelocity());
	this->setColor(entity.getColor());
	this->setMhp(entity.getMhp());
	this->setChp(entity.getChp());

	return entity;
}

char		AEntity::getLetter(void) const
{
	return this->_letter;
}

void		AEntity::setLetter(char const letter)
{
	this->_letter = letter;
}

int			AEntity::getVelocity(void) const
{
	return this->_velocity;
}

void		AEntity::setVelocity(int const velocity)
{
	this->_velocity = velocity;
}

int			AEntity::getColor(void) const
{
	return this->_color;
}

void		AEntity::setColor(int const color)
{
	this->_color = color;
}

int			AEntity::getMhp(void) const
{
	return this->_mhp;
}

void		AEntity::setMhp(int const mhp)
{
	this->_mhp = mhp;
}

int			AEntity::getChp(void) const
{
	return this->_chp;
}

void		AEntity::setChp(int const chp)
{
	this->_chp = chp;
}
