/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:31:53 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 21:35:04 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_CLASS_HPP
# define WALL_CLASS_HPP
# include "Entity.class.hpp"

class Wall : public Entity
{

public:
    Wall();
    virtual ~Wall(void);
    Wall (Wall const &wall);
    Wall const &operator=(Wall const &wall);

};
Wall &operator-=(Wall &wall, int n);

#endif
