/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:06:16 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 12:54:26 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_CLASS_HPP
# define WALL_CLASS_HPP
# include "AEntity.class.hpp"

class Wall : public AEntity
{

public:
	Wall(void);
	virtual ~Wall(void);
	Wall (Wall const &wall);
	Wall const &operator=(Wall const &wall);

	char		die();

};

#endif