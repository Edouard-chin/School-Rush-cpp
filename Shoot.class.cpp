/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:36:32 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 23:29:43 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.class.hpp"

Shoot::Shoot(int posX, int posY) : Entity(Shoot::SHOOT, 2, Shoot::RED, 50, 50, posX, posY)
{
    this->_damage = 10;
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

Shoot &operator+=(Shoot &shoot, int n)
{
    if (shoot.getPosX() + n > 100) {
        // delete &shoot;
        shoot.setPosX(100);
    } else {
        shoot.setPosX(shoot.getPosX() + n + shoot.getVelocity());
    }

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
