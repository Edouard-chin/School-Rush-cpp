/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squares.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:18:49 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 15:33:05 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squares.hpp"

/**
*********************  CONSTRUCTORS / DESTRUCTORS  ********************
*/

Squares::Squares(void) : _c(' '), _x(0), _y(0)
{
	return ;
}

Squares::Squares(char c) :  _c(c), _x(0), _y(0)
{
	return ;
}

Squares::Squares(char c, int x, int y) :  _c(c), _x(x), _y(y)
{
	return ;
}

Squares::Squares(Squares const & src) : _c(src.getC()), _x(src.getX()), _y(src.getY())
{
	return ;
}

Squares::~Squares(void)
{
	return ;
}

/**
********************  OPERATORS  ********************
*/

Squares					&Squares::operator=(Squares const & rhs)
{
	this->setX(rhs.getX());
	return (*this);
}

/**
********************  METHODS  ********************
*/


/**
*******************  GETTERS  *******************
*/

char					Squares::getC(void) const
{
	return (this->_c);
}

int						Squares::getX(void) const
{
	return (this->_x);
}

int						Squares::getY(void) const
{
	return (this->_y);
}

Squares *				Squares::getNext(void) const
{
	return (this->_next);
}


/**
*******************  SETTERS  *******************
*/

void					Squares::setC(char const c)
{
	this->_c = c;
}

void					Squares::setX(int const x)
{
	this->_x = x;
}

void					Squares::setY(int const y)
{
	this->_y = y;
}

void					Squares::setNext(Squares * next)
{
	this->_next = next;
}


/**
*******************  NON MEMBERS METHODS  *******************
*/

std::ostream			&operator<<(std::ostream & o, Squares const & rhs)
{
	o << rhs.getX() << "/" << rhs.getY() << std::endl;
	return o;
}