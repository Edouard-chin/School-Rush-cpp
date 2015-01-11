/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:59:46 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 12:59:47 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(void) : AEntity(Player::PLAYER, 0, Player::GREEN, 1, 1)
{

}

Player::~Player(void)
{

}

Player::Player (Player const &player) : AEntity(player.getLetter(), player.getVelocity(), player.getColor(), player.getMhp(), player.getChp())
{

}

Player const &Player::operator=(Player const &player)
{
	this->setLetter(player.getLetter());
	this->setVelocity(player.getVelocity());
	this->setColor(player.getColor());
	this->setMhp(player.getMhp());
	this->setChp(player.getChp());

	return player;
}

char				Player::die()
{
	std::cout << "Noooo I was so close" << std::endl;
	return ('T');
}