/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:12 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 15:20:44 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wall.class.hpp"

Wall::Wall(void) : Entity(Wall::WALL, 1, Wall::BLUE, 1, 1)
{

}

Wall::~Wall(void)
{

}

Wall::Wall (Wall const &wall) : Entity(wall.getLetter(), wall.getVelocity(), wall.getColor(), wall.getMhp(), wall.getChp())
{

}

Wall const &Wall::operator=(Wall const &wall)
{

}