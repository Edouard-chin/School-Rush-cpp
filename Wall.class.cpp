/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:32:01 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 03:38:57 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wall.class.hpp"

Wall::Wall(int posX, int posY) : Entity(Wall::WALL, 1, Wall::BLUE, 1, 1, posX, posY)
{

}

Wall::~Wall(void)
{

}

Wall::Wall (Wall const &wall) : Entity(wall.getLetter(), wall.getVelocity(), wall.getColor(), wall.getMhp(), wall.getChp(), wall.getPosX(), wall.getPosY())
{

}

Wall const &Wall::operator=(Wall const &wall)
{
    this->_letter = wall.getLetter();
    this->_velocity = wall.getVelocity();
    this->_color = wall.getColor();
    this->_mhp = wall.getMhp();
    this->_chp = wall.getChp();
    this->_posX = wall.getPosX();
    this->_posY = wall.getPosY();

    return wall;
}
