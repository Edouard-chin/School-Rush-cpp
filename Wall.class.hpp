/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:16 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 15:24:58 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_CLASS_HPP
# define WALL_CLASS_HPP
# include "Entity.class.hpp"

class Wall : public Entity
{

public:
	Wall(void);
	~Wall(void);
	Wall (Wall const &wall);
	Wall const &operator=(Wall const &wall);

};

#endif