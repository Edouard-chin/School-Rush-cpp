/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squares.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:13:35 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 16:55:05 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARES_CLASS_H
# define SQUARES_CLASS_H

# include "Entity.class.hpp"
# include <iostream>
# include <string>

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