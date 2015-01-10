/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:05:45 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 15:11:03 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.class.hpp"

Monster::Monster(void) : Entity(Monster::MONSTER, 1, Monster::RED, 50, 50)
{

}

Monster::~Monster(void)
{

}

Monster::Monster (Monster const &monster) : Entity(monster.getLetter(), monster.getVelocity(), monster.getColor(), monster.getMhp(), monster.getChp())
{

}

Monster &Monster::operator=(Monster const &monster)
{

}