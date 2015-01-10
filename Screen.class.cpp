/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:45:44 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/10 20:48:05 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.class.hpp"
#include <stdlib.h>

const	int			Screen::ESC = 27;
const	int			Screen::UP = 259;
const	int			Screen::DOWN = 258;
const 	int 		Screen::LEFT = 260;
const	int			Screen::RIGHT = 261;
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
	this->setPlayer(new Squares(new Player(), 10, 11));
	this->setSquares(this->getPlayer());
	for (int i = 0; i < this->getU(); ++i)
	{
		this->popSquares(new Squares(new Wall(), i, 0));
		this->popSquares(new Squares(new Wall(), i, 1));
		this->popSquares(new Squares(new Wall(), i, this->getV() - 1));
		this->popSquares(new Squares(new Wall(), i, this->getV() - 2));
	}
	return ;
}

void					Screen::printAll(void)
{
	Squares *			tmp = this->getSquares();

	clear();
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
	int nbOfWallsUp = (std::rand() % 4) + 2;
	int nbOfWallsDown = (std::rand() % 4) + 2;

	for (int i = 0; i < nbOfWallsUp; ++i)
		this->popSquares(new Squares(new Wall(), this->getU() - 1, i));
	for (int i = 0; i < nbOfWallsDown; ++i)
		this->popSquares(new Squares(new Wall(), this->getU() - 1, this->getV() - 1 - i));
}

void						Screen::generateNewMonster()
{
	int					randomY;
	int					randomValid;

	randomY = ((std::rand() % (this->getV() - 10)) + 5);
	randomValid = ((std::rand() % 15) + randomY);
	if (randomY == randomValid)
		this->popSquares(new Squares(new Monster(), this->getU() - 1, randomY));
	// TODO check si case deja prise en Y
	return ;
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
			if ((collide = this->checkCollision(tmp)))
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
		if (s != tmp && s->getX() == tmp->getX() && s->getY() == tmp->getY())
			return (tmp);
		tmp = tmp->getNext();
	}
	return (NULL);
}

int						Screen::newTurn()
{
	Squares *			tmp = this->getSquares();
	Squares *			player = this->getPlayer();
	int					key;

	key = this->curses_input();
	std::cout << key << std::endl;
	if (key == Screen::ESC)
		return (key);
	else if (key == Screen::DOWN)
		player->move(0, 1);
	else if (key == Screen::UP)
		player->move(0, -1);
	else if (key == Screen::RIGHT)
		player->move(1, 0);
	else if (key == Screen::LEFT)
		player->move(-1, 0);
	else if (key == Screen::SPACE)
		this->popSquares(new Squares(new Shoot(), player->getX() + 1, player->getY()));

	while(tmp)
	{
		tmp->move();
		tmp = tmp->getNext();
	}
	this->clearScreen();
	this->generateNewWalls();
	this->generateNewMonster();
	this->checkCollision();
	this->printAll();

	return (key);
}

void 					Screen::initTerm( int u, int v )
{
	initscr(); /* Init the screen */
	keypad(stdscr, TRUE);
	if (getenv("ESCDELAY") == NULL) {
		ESCDELAY = 1;
	}
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

	timeout(50);
	ch = wgetch(stdscr);

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

Squares *				Screen::getPlayer(void) const
{
	return (this->_player);
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

void					Screen::setSquares(Squares * squares)
{
	this->_squares = squares;
}

void					Screen::setPlayer(Squares * player)
{
	this->_player = player;
}

/**
*******************  NON MEMBERS METHODS  *******************
*/

std::ostream			&operator<<(std::ostream & o, Screen const & rhs)
{
	o << rhs.getU() << "/" << rhs.getV() << std::endl;
	return o;
}