/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:05 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 16:37:22 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.class.hpp"

Shoot::Shoot(void) : Entity(Shoot::SHOOT, 1, Shoot::RED, 50, 50)
{

}

Shoot::~Shoot(void)
{

}

Shoot::Shoot (Shoot const &shoot) : Entity(shoot.getLetter(), shoot.getVelocity(), shoot.getColor(), shoot.getMhp(), shoot.getChp())
{

}

Shoot &Shoot::operator=(Shoot const &shoot)
{

}

int		Shoot::getDamage(void) const
{
	return this->_damage;
}

void	Shoot::setDamage(int damage)
{
	this->_damage = damage;
}