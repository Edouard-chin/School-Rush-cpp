/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:34:35 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 03:38:45 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(int posX, int posY) : Entity(Player::PLAYER, 0, Player::GREEN, 1, 1, posX, posY)
{

}

Player::~Player(void)
{

}

Player::Player (Player const &player) : Entity(player.getLetter(), player.getVelocity(), player.getColor(), player.getMhp(), player.getChp(), player.getPosX(), player.getPosY())
{

}

Player const &Player::operator=(Player const &player)
{
    this->_letter = player.getLetter();
    this->_velocity = player.getVelocity();
    this->_color = player.getColor();
    this->_mhp = player.getMhp();
    this->_chp = player.getChp();
    this->_posX = player.getPosX();
    this->_posY = player.getPosY();

    return player;
}
