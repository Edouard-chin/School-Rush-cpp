/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squares.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:18:49 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 17:02:09 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squares.class.hpp"

/**
*********************  CONSTRUCTORS / DESTRUCTORS  ********************
*/

Squares::Squares(void) : _x(0), _y(0), _next(0), _e(0)
{
	return ;
}

Squares::Squares(Entity * e, int x, int y) : _x(x), _y(y), _next(0), _e(e)
{
	return ;
}

Squares::Squares(Squares const & src) : _x(src.getX()), _y(src.getY()), _next(src.getNext()), _e(src.getEntity())
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
	this->setY(rhs.getY());
	this->setNext(rhs.getNext());
	this->setEntity(rhs.getEntity());
	return (*this);
}

/**
********************  METHODS  ********************
*/

void					Squares::die()
{
	delete this->getEntity();
	this->setEntity(NULL);
}

void					Squares::move()
{
	this->setX(this->getX() - this->getEntity()->getVelocity());
}

void					Squares::move(int x, int y)
{
	this->setX(this->getX() + x);
	this->setY(this->getY() + y);
}

/**
*******************  GETTERS  *******************
*/

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

Entity *				Squares::getEntity(void) const
{
	return (this->_e);
}


/**
*******************  SETTERS  *******************
*/

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

void					Squares::setEntity(Entity * e)
{
	this->_e = e;
}


/**
*******************  NON MEMBERS METHODS  *******************
*/

std::ostream			&operator<<(std::ostream & o, Squares const & rhs)
{
	o << rhs.getX() << "/" << rhs.getY() << std::endl;
	return o;
}

std::ostream			&operator<<(std::ostream & o, Squares const * rhs)
{
	o << rhs->getX() << "/" << rhs->getY() << std::endl;
	return o;
}