/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:36:32 by echin             #+#    #+#             */
/*   Updated: 2015/01/12 04:50:08 by echin            ###   ########.fr       */
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

int operator+=(Shoot &shoot, Monster *monster)
{
    int   posX = 0;
    int   score = 0;

    for (int i = 0; i < 20; i++) {
        posX = monster[i].getPosX();
        if ((shoot.getPosX() == posX + 1 || shoot.getPosX() == posX -1 || shoot.getPosX() == posX) && shoot.getPosY() == monster[i].getPosY()) {
            monster[i].die();
            shoot.die();
            score = 1;
        }
    }

    if (shoot.getPosX() + 1 > 100) {
        shoot.setPosX(100);
        shoot.setPosY(40);
    } else {
        shoot.setPosX(shoot.getPosX() + 1);
    }

    return score;
}

int     Shoot::getDamage(void) const
{
    return this->_damage;
}

void    Shoot::setDamage(int damage)
{
    this->_damage = damage;
}
