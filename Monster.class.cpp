/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:19:40 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 05:41:10 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.class.hpp"

Monster::Monster(void) : Entity(Entity::MONSTER, 1, Entity::RED, 30, 30, this->generateCoordinate(30, 100), this->generateCoordinate(0, 100))
{

}

Monster::~Monster(void)
{

}

Monster::Monster(Monster const & monster) : Entity(monster.getLetter(), 1, monster.getColor(), monster.getMhp(), monster.getChp(), monster.getPosX(), monster.getPosY())
{

}

Monster const & Monster::operator=(Monster const & monster)
{
    this->_letter   = monster.getLetter();
    this->_velocity = monster.getVelocity();
    this->_color    = monster.getColor();
    this->_mhp      = monster.getMhp();
    this->_chp      = monster.getChp();
    this->_posX     = monster.getPosX();
    this->_posY     = monster.getPosY();

    return monster;
}

Monster &operator-=(Monster &monster, int n)
{
    if (monster.getPosX() - n < 0) {
        monster.die();
    } else {
        monster.setPosX(monster.getPosX() - n);
    }

    return monster;
}
