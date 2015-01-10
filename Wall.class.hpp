/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:16 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 17:15:41 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_CLASS_HPP
# define WALL_CLASS_HPP
# include "Entity.class.hpp"

class Wall : public Entity
{

public:
	Wall(void);
	virtual ~Wall(void);
	Wall (Wall const &wall);
	Wall const &operator=(Wall const &wall);

};

#endif