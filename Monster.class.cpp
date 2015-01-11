/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:19:40 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 03:14:59 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.class.hpp"

Monster::Monster(int posX, int posY) : Entity(Entity::MONSTER, 1, Entity::RED, 30, 30, posX, posY)
{

}

Monster::~Monster()
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
