/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:34:24 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 06:22:39 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP
# include "Entity.class.hpp"

class Player : public Entity
{

public:
    Player(int posX, int posY);
    virtual ~Player(void);
    Player (Player const &player);
    Player const &operator=(Player const &player);

};

Player &operator-=(Player &player, int n);
Player &operator+=(Player &player, int n);
Player &operator-(Player &player, int n);
Player &operator+(Player &player, int n);

#endif
