/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:36:32 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 03:39:47 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.class.hpp"

Shoot::Shoot(int posX, int posY) : Entity(Shoot::SHOOT, -1, Shoot::RED, 50, 50, posX, posY)
{

}

Shoot::~Shoot(void)
{

}

Shoot::Shoot (Shoot const &shoot) : Entity(shoot.getLetter(), shoot.getVelocity(), shoot.getColor(), shoot.getMhp(), shoot.getChp(), shoot.getPosX(), shoot.getPosY())
{

}

Shoot const &Shoot::operator=(Shoot const &shoot)
{
    this->_letter = shoot.getLetter();
    this->_velocity = shoot.getVelocity();
    this->_color = shoot.getColor();
    this->_mhp = shoot.getMhp();
    this->_chp = shoot.getChp();
    this->_posX = shoot.getPosX();
    this->_posY = shoot.getPosY();

    return shoot;
}

int     Shoot::getDamage(void) const
{
    return this->_damage;
}

void    Shoot::setDamage(int damage)
{
    this->_damage = damage;
}
