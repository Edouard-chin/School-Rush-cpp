/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squares.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:13:35 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 15:33:22 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARES_H
# define SQUARES_H

//# include "Entities.hpp"
# include <iostream>
# include <string>

class Squares {
public:
	Squares(void);
	Squares(char);						// la lettre a affiche, si pas objet entities
	Squares(char, int, int);			// lettre + x + y
	//Squares(Entities);				// entite stocke directement dedans
	Squares(Squares const & src);
	virtual ~Squares(void);

	Squares				&operator=(Squares const & rhs);

	char				getC() const;
	int					getX() const;
	int					getY() const;
	Squares *			getNext() const;

	void				setC(char const);
	void				setX(int const);
	void				setY(int const);
	void				setNext(Squares *);


private:
	char				_c;		// si no entities afficher ce char (' ' allowed)
	int					_x;		// x position
	int					_y;		// y position
	Squares *			_next;	// liste chainee
//	Entities			_e;		// contient l'entite a afficher
};

std::ostream			&operator<<(std::ostream & o, Squares const & rhs);

#endif