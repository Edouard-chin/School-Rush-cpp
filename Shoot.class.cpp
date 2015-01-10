/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:05 by echin             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/10 16:37:22 by fbaudet-         ###   ########.fr       */
=======
/*   Updated: 2015/01/10 16:47:45 by echin            ###   ########.fr       */
>>>>>>> master
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

Shoot const &Shoot::operator=(Shoot const &shoot)
{
	this->_letter = shoot.getLetter();
	this->_velocity = shoot.getVelocity();
	this->_color = shoot.getColor();
	this->_mhp = shoot.getMhp();
	this->_chp = shoot.getChp();

	return shoot;
}

int		Shoot::getDamage(void) const
{
	return this->_damage;
}

void	Shoot::setDamage(int damage)
{
	this->_damage = damage;
}