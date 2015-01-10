/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:59:46 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 17:30:45 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(void) : Entity(Player::PLAYER, 0, Player::GREEN, 1, 1)
{

}

Player::~Player(void)
{

}

Player::Player (Player const &player) : Entity(player.getLetter(), player.getVelocity(), player.getColor(), player.getMhp(), player.getChp())
{

}

Player const &Player::operator=(Player const &player)
{
	this->_letter = player.getLetter();
	this->_velocity = player.getVelocity();
	this->_color = player.getColor();
	this->_mhp = player.getMhp();
	this->_chp = player.getChp();

	return player;
}