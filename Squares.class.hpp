/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squares.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:13:35 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 16:01:24 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARES_H
# define SQUARES_H

# include "Entity.class.hpp"
# include <iostream>
# include <string>

class Squares {
public:
	Squares(void);
	Squares(Entity *, int, int);			// entite stocke directement dedans
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


private:
	int					_x;		// x position
	int					_y;		// y position
	Squares *			_next;	// liste chainee
	Entity *			_e;		// contient l'entite a afficher
};

std::ostream			&operator<<(std::ostream & o, Squares const & rhs);

#endif