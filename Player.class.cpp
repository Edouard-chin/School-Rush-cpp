/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:59:46 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 16:37:18 by fbaudet-         ###   ########.fr       */
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

}