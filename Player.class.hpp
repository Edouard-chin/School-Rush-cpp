/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:59:53 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 15:24:46 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP
# include "Entity.class.hpp"

class Player : public Entity
{

public:
	Player(void);
	~Player(void);
	Player (Player const &player);
	Player const &operator=(Player const &player);

};

#endif 