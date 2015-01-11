/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:49:40 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 05:40:26 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.class.hpp"
#include <cstdlib>

const    char        Entity::MONSTER = 'M';
const    char        Entity::PLAYER = 'P';
const    char        Entity::WALL = 'W';
const    char        Entity::SHOOT = '*';
const    int         Entity::RED = 1;
const    int         Entity::GREEN = 2;
const    int         Entity::BLUE = 3;


Entity::Entity(char letter, int velocity, int color, int mhp, int chp, int posX, int posY) : _letter(letter), _velocity(velocity), _color(color), _mhp(mhp), _chp(chp), _posX(posX), _posY(posY)
{

}

Entity::~Entity()
{

}

Entity::Entity(Entity const & entity) : _letter(entity.getLetter()), _velocity(entity.getVelocity()), _color(entity.getColor()), _mhp(entity.getMhp()), _posX(entity.getPosX()), _posY(entity.getPosY())
{

}

Entity const & Entity::operator=(Entity const & entity)
{
    this->_letter = entity.getLetter();
    this->_velocity = entity.getVelocity();
    this->_color = entity.getColor();
    this->_mhp = entity.getMhp();
    this->_chp = entity.getChp();
    this->_posX = entity.getPosX();
    this->_posY = entity.getPosY();

    return entity;
}

char        Entity::getLetter(void) const
{
    return this->_letter;
}

void        Entity::setLetter(char letter)
{
    this->_letter = letter;
}

int         Entity::getVelocity(void) const
{
    return this->_velocity;
}

void        Entity::setVelocity(int velocity)
{
    this->_velocity = velocity;
}

int         Entity::getColor(void) const
{
    return this->_color;
}

void        Entity::setColor(int color)
{
    this->_color = color;
}

int         Entity::getMhp(void) const
{
    return this->_mhp;
}

void        Entity::setMhp(int mhp)
{
    this->_mhp = mhp;
}

int         Entity::getChp(void) const
{
    return this->_chp;
}

void        Entity::setChp(int chp)
{
    this->_chp = chp;
}

int         Entity::getPosX(void) const
{
    return this->_posX;
}

void        Entity::setPosX(int posX)
{
    this->_posX = posX;
}

int         Entity::getPosY(void) const
{
    return this->_posY;
}

void        Entity::setPosY(int posY)
{
    this->_posY = posY;
}

void        Entity::die()
{
    this->setPosX(100);
    this->setPosY(this->generateCoordinate(0, 100));
}

int         Entity::generateCoordinate(int min, int max)
{
    int randNum = rand()%(min-max + 1) + min;

    return randNum;
}
