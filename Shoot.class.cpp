/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:05 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 20:20:58 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.class.hpp"

Shoot::Shoot(void) : Entity(Shoot::SHOOT, -1, Shoot::RED, 50, 50)
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