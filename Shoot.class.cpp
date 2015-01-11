/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:05 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 13:00:43 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.class.hpp"

Shoot::Shoot(void) : AEntity(Shoot::SHOOT, -1, Shoot::RED, 50, 50)
{

}

Shoot::~Shoot(void)
{

}

Shoot::Shoot (Shoot const &shoot) : AEntity(shoot.getLetter(), shoot.getVelocity(), shoot.getColor(), shoot.getMhp(), shoot.getChp())
{

}

Shoot const &Shoot::operator=(Shoot const &shoot)
{
	this->setLetter(shoot.getLetter());
	this->setVelocity(shoot.getVelocity());
	this->setColor(shoot.getColor());
	this->setMhp(shoot.getMhp());
	this->setChp(shoot.getChp());

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

char				Shoot::die()
{
	std::cout << "Piouf" << std::endl;
	return (':');
}