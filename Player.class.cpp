/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:34:35 by echin             #+#    #+#             */
/*   Updated: 2015/01/12 00:38:28 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(int posX, int posY) : Entity(Player::PLAYER, 1, Player::GREEN, 1, 1, posX, posY)
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

Player &operator-=(Player &player, int n)
{
    if (player.getPosX() - n < 0) {
        player.setPosX(0);
    } else {
        player.setPosX(player.getPosX() - n);
    }

    return player;
}

Player &operator+=(Player &player, int n)
{
    if (player.getPosX() + n > 100) {
        player.setPosX(100);
    } else {
        player.setPosX(player.getPosX() + n);
    }

    return player;
}

Player &operator-(Player &player, int n)
{
    if (player.getPosY() + n > 100) {
        player.setPosY(100);
    } else {
        player.setPosY(player.getPosY() + n);
    }

    return player;
}

Player &operator+(Player &player, int n)
{
    if (player.getPosY() - n < 0) {
        player.setPosY(0);
    } else {
        player.setPosY(player.getPosY() - n);
    }

    return player;
}
