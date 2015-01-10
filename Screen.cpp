/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:45:44 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 15:35:07 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"

/**
*********************  CONSTRUCTORS / DESTRUCTORS  ********************
*/

Screen::Screen(void) : _u(80), _v(25), _squares(NULL)
{	
	std::srand(std::time(0));
	return ;
}

Screen::Screen(int u, int v) : _u(u), _v(v), _squares(NULL)
{
	std::srand(std::time(0));
	return ;
}

Screen::Screen(Screen const & src) : _u(src.getU()), _v(src.getV()), _squares(src.getSquares())
{
	std::srand(std::time(0));
	return ;
}

Screen::~Screen(void)
{
	return ;
}

/**
********************  OPERATORS  ********************
*/

Screen					&Screen::operator=(Screen const & rhs)
{
	this->setU(rhs.getU());
	return (*this);
}

/**
********************  METHODS  ********************
*/

void					Screen::initGame(void)
{
	this->setSquares(new Squares('#'));
	this->getSquares();
	return ;
}

void					Screen::printAll(void)
{
	Squares *			tmp = this->getSquares();

	while(tmp)
	{
		std::cout << tmp->getC();
		tmp = tmp->getNext();
	}
	std::cout << std::endl;
	return ;
}

Squares *				Screen::popSquares(Squares * s)
{
	s->setNext(this->getSquares());
	this->setSquares(s);
	return (s);
}

Squares *				Screen::pushSquares(Squares * s)
{
	Squares *			tmp = this->getLastSquares();

	tmp->setNext(s);
	return (s);
}

Squares *				Screen::killSquares(Squares * dead)
{
	Squares *			prev = this->getSquares();

	if (dead == NULL)
		return (NULL);
	if (prev == dead)
	{
		this->setSquares(dead->getNext());
		delete dead;
	}
	else
	{
		while (prev)
		{
			if (prev->getNext() == dead)
			{
				prev->setNext(dead->getNext());
				delete dead;
				return (prev);
			}
			prev = prev->getNext();
		}
	}
	return (NULL);
}

void					Screen::clearScreen()
{
	Squares *			tmp = this->getSquares();

	while(tmp)
	{
		if (tmp->getX() < 0 || tmp->getX() >= this->getU())
		{
			tmp = this->killSquares(tmp);
		}
		tmp = tmp->getNext();
	}
}

void					Screen::generateNewWalls()
{
	int nbOfWallsUp = std::rand() % 4;
	int nbOfWallsDown = std::rand() % 4;

	for (int i = 0; i < nbOfWallsUp; ++i)
		this->popSquares(new Squares('3', this->getU() - 1, i));
	for (int i = 0; i < nbOfWallsDown; ++i)
		this->popSquares(new Squares('6', this->getU() - 1, this->getV() - 1 - i));
}

int						Screen::generateNewMonster()
{
	int					nbMonsterIn = 0;
	Squares *			tmp = this->getSquares();
	int					randomY;

	while(tmp)
	{
		if (tmp->getC() == '1')	// entity
			nbMonsterIn++;
		tmp = tmp->getNext();
	}

	if (nbMonsterIn < 5)
	{
		randomY = ((std::rand() % (this->getV() - 10)) + 5);
		this->popSquares(new Squares('1', this->getU() - 1, randomY)); // entity
		nbMonsterIn++;
	}

	return (nbMonsterIn);
}

void					Screen::checkCollision()
{
	Squares *			tmp = this->getSquares();
	Squares *			collide = NULL;

	while(tmp)
	{
		if (tmp->getC() == '#')	// entity // if player
		{
			if (collide = this->checkCollision(tmp))
			{
				// collide->die();
				// tmp->die();
			}
		}
		tmp = tmp->getNext();
	}	
}

Squares *				Screen::checkCollision(Squares * s)
{
	Squares *			tmp = this->getSquares();

	while(tmp)
	{
		if (s->getX() == tmp->getX() && s->getY() == tmp->getY())
			return (tmp);
		tmp = tmp->getNext();
	}
	return (NULL);
}

/**
*******************  GETTERS  *******************
*/

int						Screen::getU() const
{
	return (this->_u);
}

int						Screen::getV() const
{
	return (this->_v);
}

Squares *				Screen::getSquares() const
{
	return (this->_squares);
}

Squares *				Screen::getLastSquares(void) const
{
	Squares *			tmp = this->getSquares();
	if (tmp)
	{
		while (tmp->getNext())
			tmp = tmp->getNext();
	}
	return (tmp);
}

/**
*******************  SETTERS  *******************
*/

void					Screen::setU(int const u)
{
	this->_u = u;
}

void					Screen::setV(int const v)
{
	this->_v = v;
}

void					Screen::setSquares(Squares * s)
{
	this->_squares = s;
}


/**
*******************  NON MEMBERS METHODS  *******************
*/

std::ostream			&operator<<(std::ostream & o, Screen const & rhs)
{
	o << rhs.getU() << "/" << rhs.getV() << std::endl;
	return o;
}