/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squares.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:13:35 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/11 12:47:31 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARES_CLASS_H
# define SQUARES_CLASS_H

# include "AEntity.class.hpp"
# include <iostream>

class Squares {
public:
	Squares(void);
	Squares(AEntity *, int, int);
	Squares(Squares const & src);
	virtual ~Squares(void);

	Squares				&operator=(Squares const & rhs);

	int					getX() const;
	int					getY() const;
	Squares *			getNext() const;
	AEntity *			getEntity() const;

	void				setX(int const);
	void				setY(int const);
	void				setNext(Squares *);
	void				setEntity(AEntity *);

	void				die();
	void				move();
	void				move(int, int);

private:
	int					_x;
	int					_y;
	Squares *			_next;
	AEntity *			_e;
};

std::ostream			&operator<<(std::ostream & o, Squares const & rhs);

#endif