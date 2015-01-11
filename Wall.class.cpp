/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:12 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 13:01:17 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wall.class.hpp"

Wall::Wall(void) : AEntity(Wall::WALL, 1, Wall::BLUE, 1, 1)
{

}

Wall::~Wall(void)
{

}

Wall::Wall (Wall const &wall) : AEntity(wall.getLetter(), wall.getVelocity(), wall.getColor(), wall.getMhp(), wall.getChp())
{

}

Wall const &Wall::operator=(Wall const &wall)
{
	this->setLetter(wall.getLetter());
	this->setVelocity(wall.getVelocity());
	this->setColor(wall.getColor());
	this->setMhp(wall.getMhp());
	this->setChp(wall.getChp());

	return wall;
}

char				Wall::die()
{
	return ('_');
}