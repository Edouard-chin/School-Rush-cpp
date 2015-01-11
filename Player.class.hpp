/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:59:53 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 12:54:27 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP
# include "AEntity.class.hpp"

class Player : public AEntity
{

public:
	Player(void);
	virtual ~Player(void);
	Player (Player const &player);
	Player const &operator=(Player const &player);

	char		die();

};

#endif 