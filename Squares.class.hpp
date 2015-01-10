/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squares.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:13:35 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 18:05:17 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARES_CLASS_H
# define SQUARES_CLASS_H

# include "Entity.class.hpp"
# include <iostream>

class Squares {
public:
	Squares(void);
	Squares(Entity *, int, int);
	Squares(Squares const & src);
	virtual ~Squares(void);

	Squares				&operator=(Squares const & rhs);

	int					getX() const;
	int					getY() const;
	Squares *			getNext() const;
	Entity *			getEntity() const;

	void				setX(int const);
	void				setY(int const);
	void				setNext(Squares *);
	void				setEntity(Entity *);

	void				die();
	void				move();
	void				move(int, int);

private:
	int					_x;
	int					_y;
	Squares *			_next;
	Entity *			_e;
};

std::ostream			&operator<<(std::ostream & o, Squares const & rhs);

#endif