/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:59:53 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 17:15:01 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP
# include "Entity.class.hpp"

class Player : public Entity
{

public:
	Player(void);
	virtual ~Player(void);
	Player (Player const &player);
	Player const &operator=(Player const &player);

};

#endif 