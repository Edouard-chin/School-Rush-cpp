/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:34:35 by echin             #+#    #+#             */
/*   Updated: 2015/01/12 06:04:11 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"
#include "unistd.h"

Player::Player(int posX, int posY) : Entity(Player::PLAYER, 1, Player::GREEN, 100, 100, posX, posY)
{
    this->setScore(0);
    this->setLife(3);
}

Player::~Player(void)
{

}

Player::Player (Player const &player) : Entity(player.getLetter(), player.getVelocity(), player.getColor(), player.getMhp(), player.getChp(), player.getPosX(), player.getPosY())
{
    this->setScore(0);
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
    this->_score = player.getScore();

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
    if (player.getPosX() + n >= 100) {
        player.setPosX(99);
    } else {
        player.setPosX(player.getPosX() + n);
    }

    return player;
}

Player &operator-(Player &player, int n)
{
    if (player.getPosY() + n >= 30) {
        player.setPosY(29);
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

bool    operator --(Player &player)
{
    if (player.getLife() -1 == 0) {
        sleep(1);
        return true;
    } else {
        player.setPosX(player.getPosX() + 2);
        player.setLife(player.getLife() - 1);
        sleep(1);
    }

    return false;
}


int    Player::getScore(void) const
{
    return this->_score;
}

void   Player::setScore(int score)
{
    this->_score = score;
}

int    Player::getLife(void) const
{
    return this->_life;
}

void   Player::setLife(int life)
{
    this->_life = life;
}
