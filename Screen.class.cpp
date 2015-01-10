/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:45:44 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 18:52:14 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.class.hpp"

const	int			Screen::ESC = 27;
const	int			Screen::UP = 119;
const	int			Screen::DOWN = 115;
const 	int 		Screen::LEFT = 97;
const	int			Screen::RIGHT = 100;
const	int			Screen::ENTER = 10;
const	int			Screen::SPACE = 32;


/**
*********************  CONSTRUCTORS / DESTRUCTORS  ********************
*/

Screen::Screen(void) : _u(80), _v(25), _squares(NULL)
{	
	std::srand(std::time(0));
	this->initTerm(_u, _v);

	return ;
}

Screen::Screen(int u, int v) : _u(u), _v(v), _squares(NULL)
{
	std::srand(std::time(0));
	this->initTerm(_u, _v);

	return ;
}

Screen::Screen(Screen const & src) : _u(src.getU()), _v(src.getV()), _squares(src.getSquares())
{
	std::srand(std::time(0));
	return ;
}

Screen::~Screen(void)
{
	clear();
	endwin();	

	return;
}

/**
********************  OPERATORS  ********************
*/

Screen					&Screen::operator=(Screen const & rhs)
{
	this->setU(rhs.getU());
	this->setV(rhs.getV());
	this->setSquares(rhs.getSquares());
	return (*this);
}

/**
********************  METHODS  ********************
*/

void					Screen::initGame(void)
{
	this->setSquares(new Squares(new Wall(), 0, 0));
	return ;
}

void					Screen::printAll(void)
{
	Squares *			tmp = this->getSquares();

	while(tmp)
	{
		this->curses_print(tmp->getX(), tmp->getY(), tmp->getEntity()->getLetter(), tmp->getEntity()->getColor());
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
		dead->die();
		delete dead;
	}
	else
	{
		while (prev)
		{
			if (prev->getNext() == dead)
			{
				prev->setNext(dead->getNext());
				dead->die();
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
		this->popSquares(new Squares(new Wall(), this->getU() - 1, i));
	for (int i = 0; i < nbOfWallsDown; ++i)
		this->popSquares(new Squares(new Wall(), this->getU() - 1, this->getV() - 1 - i));
}

int						Screen::generateNewMonster()
{
	int					nbMonsterIn = 0;
	Squares *			tmp = this->getSquares();
	int					randomY;

	while(tmp)
	{
		if (tmp->getEntity()->getLetter() == Entity::MONSTER)
			nbMonsterIn++;
		tmp = tmp->getNext();
	}

	if (nbMonsterIn < 5)
	{
		randomY = ((std::rand() % (this->getV() - 10)) + 5);
		this->popSquares(new Squares(new Monster(), this->getU() - 1, randomY));
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
		if (tmp->getEntity()->getLetter() == Entity::PLAYER
			|| tmp->getEntity()->getLetter() == Entity::SHOOT)
		{
			if (collide = this->checkCollision(tmp))
			{
				this->killSquares(collide);
				this->killSquares(tmp);
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

void					Screen::newTurn()
{
	Squares *			tmp = this->getSquares();

	while(tmp)
	{
		tmp->move();
		tmp = tmp->getNext();
	}
}

void 					Screen::initTerm( int u, int v )
{
	initscr(); /* Init the screen */
	noecho(); /* No echo in the screen */
	curs_set(0); /* Hide the cursor */
	resizeterm(v, u); /* Resize the ncurse grid */
	start_color(); 		/* Init color */
    init_pair(1, 1, 0); /* RED */
    init_pair(2, 2, 0); /* GREEN */
    init_pair(3, 3, 0); /* YELLOW */
    init_pair(4, 4, 0); /* BLUE */
    init_pair(5, 5, 0); /* MAGENTA */
    init_pair(6, 6, 0); /* CYAN */
}

void 					Screen::curses_print( int x, int y, char c, int color)
{
	attron(COLOR_PAIR(color));
	mvprintw( y, x, "%c", c );
	attroff(COLOR_PAIR(color));
	refresh();

	return;
}

int 					Screen::curses_input( void )
{
	int ch;

	timeout(100);
	ch = getch();

	return ch;
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