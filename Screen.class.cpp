/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:45:44 by fbaudet-          #+#    #+#             */
/*   Updated: 2015/01/11 15:45:43 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.class.hpp"

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

Screen::Screen(void) : _u(80), _v(25), _score(0), _time(std::time(0)), _squares(NULL)
{	
	std::srand(std::time(0));
	this->initTerm(_u, _v);

	return ;
}

Screen::Screen(int u, int v) : _u(u), _v(v), _score(0), _squares(NULL)
{
	if (_u <= 0)
		_u = 80;
	if (_v <= 0)
		_v = 25;
	std::srand(std::time(0));
	this->initTerm(_u, _v);

	return ;
}

Screen::Screen(Screen const & src) : _u(src.getU()), _v(src.getV()), _score(src.getScore()), _time(src.getTime()), _squares(src.getSquares())
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
	this->setScore(rhs.getScore());
	this->setSquares(rhs.getSquares());
	return (*this);
}

/**
********************  METHODS  ********************
*/

void					Screen::initGame(void)
{
	this->printIntro();
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

void					Screen::quitGame(void)
{
	Squares *			tmp = this->getSquares();
	Squares *			nxt = NULL;

	while(tmp)
	{
		nxt = tmp->getNext();
		this->killSquares(tmp);
		tmp = nxt;
	}
}

void					Screen::printAll(void)
{
	Squares *			tmp = this->getSquares();

	clear();
	while(tmp)
	{
		this->cursesPrint(tmp->getX(), tmp->getY(), tmp->getEntity()->getLetter(), tmp->getEntity()->getColor());
		tmp = tmp->getNext();
	}
	attron(COLOR_PAIR(6));
	mvprintw( this->getV(), 5,"Score: %d", this->getScore() );
	mvprintw( this->getV() + 1, 5,"Time:  %d", std::time(0) - this->getTime() );
	if (this->getPlayer())
		mvprintw( this->getV() + 2, 5,"Life:  %d", this->getPlayer()->getEntity()->getChp() );
	attron(COLOR_PAIR(6));
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

void					Screen::moveSquares(char const type)
{
	Squares *			tmp = this->getSquares();

	while(tmp)
	{
		if (tmp->getEntity()->getLetter() == type)
			tmp->move();
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

void					Screen::generateNewMonster()
{
	int					randomY;
	int					randomValid;
	int					difficulty;

	difficulty = 15 - (this->getScore() / 2);
	if (difficulty <= 0)
		difficulty = 1;
	randomY = ((std::rand() % (this->getV() - 10)) + 5);
	randomValid = ((std::rand() % difficulty) + randomY);
	if (randomY == randomValid)
		this->popSquares(new Squares(new Monster(), this->getU() - 1, randomY));
	return ;
}

void					Screen::checkCollision()
{
	Squares *			tmp = this->getSquares();
	Squares *			collide = NULL;

	while(tmp)
	{
		if (tmp->getEntity()->getLetter() == AEntity::PLAYER
			|| tmp->getEntity()->getLetter() == AEntity::SHOOT)
		{
			if ((collide = this->checkCollision(tmp)))
			{
				if (tmp->getEntity()->getLetter() == AEntity::PLAYER)
				{
					tmp->getEntity()->setChp(tmp->getEntity()->getChp() - 1);
					if (tmp->getEntity()->getChp() == 0)
					{
						this->setPlayer(NULL);
						this->killSquares(tmp);
						return ;
					}
				}
				else if (collide->getEntity()->getLetter() == AEntity::MONSTER)
					this->setScore(this->getScore() + 1);
				this->killSquares(collide);
				if (tmp->getEntity()->getLetter() != AEntity::PLAYER)
					this->killSquares(tmp);
			}
		}
		tmp = tmp->getNext();
	}	
}

Squares *				Screen::checkCollision(Squares * s) const
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

int						Screen::checkContinue(int key) const
{
	if (this->getPlayer() == NULL)
		return (Screen::ESC);
	else if (this->getPlayer()->getX() < 0 || this->getPlayer()->getX() > this->getU())
		return (Screen::ESC);
	else
		return (key);
}

int						Screen::newTurn()
{
	Squares *			player = this->getPlayer();
	int					key;

	key = this->cursesInput();
	if (key == Screen::DOWN)
		player->move(0, 1);
	else if (key == Screen::UP)
		player->move(0, -1);
	else if (key == Screen::RIGHT)
		player->move(1, 0);
	else if (key == Screen::LEFT)
		player->move(-1, 0);
	else if (key == Screen::SPACE)
		this->popSquares(new Squares(new Shoot(), player->getX() + 1, player->getY()));

	this->moveSquares(AEntity::WALL);
	this->moveSquares(AEntity::MONSTER);
	this->checkCollision();
	this->generateNewWalls();
	this->generateNewMonster();
	this->moveSquares(AEntity::SHOOT);
	this->checkCollision();
	this->clearScreen();
	this->printAll();
	key = this->checkContinue(key);

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
	resizeterm(v + 3, u); /* Resize the ncurse grid */
	start_color(); 		/* Init color */
    init_pair(1, 1, 0); /* RED */
    init_pair(2, 2, 0); /* GREEN */
    init_pair(3, 3, 0); /* YELLOW */
    init_pair(4, 4, 0); /* BLUE */
    init_pair(5, 5, 0); /* MAGENTA */
    init_pair(6, 6, 0); /* CYAN */
}

void 					Screen::cursesPrint( int x, int y, char c, int color)
{
	attron(COLOR_PAIR(color));
	mvprintw( y, x, "%c", c );
	attroff(COLOR_PAIR(color));
	refresh();

	return;
}

int 					Screen::cursesInput( void )
{
	int 	ch;

	timeout(50);
	ch = wgetch(stdscr);

	return ch;
}

void					Screen::makeBorder( int xmin, int ymin, int xmax, int ymax ) 
{

	int i;
	int j;

	i = ymin;

	while (i < ymax) {

		if (i == ymin || i == ymax-1) {

			j = xmin;
			while (j < xmax) {
				mvprintw(i, j ,"%c", '*');
				j++;
			}
		} else {
			mvprintw( i, xmin,"%c", '*');
			mvprintw( i, xmax - 1,"%c", '*');
		}
		i++;
	}
}

void		 			Screen::printIntro( void )
{

	int 	i;
	int 	ch;

	i = 1;

	std::string	play("Press ENTER to play");

	while ( 42 ) {	
		
		timeout(500);
		ch = getch();

		clear();

		switch ( ch ) {

			case Screen::ENTER:
				return;

			default:
				if (i) {
					i = 0;
					attron(COLOR_PAIR(1));
					makeBorder( 0, 0, this->getU(), this->getV() );
					attron(COLOR_PAIR(2));
					attron(COLOR_PAIR(3));
					makeBorder( this->getU()/2 - play.size()/2 - 2, ((this->getV() - 1)/2)*this->getV()/this->getV() - 1, this->getU()/2 + play.size()/2 + 3, ((this->getV() - 1)/2)*this->getV()/this->getV() + 2);
					attroff(COLOR_PAIR(3));
					mvprintw( ((this->getV() - 1)/2)*this->getV()/this->getV(), this->getU()/2 - play.size()/2 ,"%s", play.c_str() );
					attroff(COLOR_PAIR(2));
					attroff(COLOR_PAIR(1));
				} else {
					i = 1;
					attron(COLOR_PAIR(1));
					makeBorder( 0, 0, this->getU(), this->getV() );
					attroff(COLOR_PAIR(1));
				}
		}
		refresh();
	}
}

void		 Screen::printOutro( void )
{
	int 	ch;
	int 	ptime;

	ptime = std::time(0) - this->getTime();

	std::string	msg("GAME OVER");
	std::string quit("Press ENTER to quit");

	while ( 42 ) {	
		
		ch = getch();

		clear();

		switch ( ch ) {

			case Screen::ENTER:
				return;

			default:
				attron(COLOR_PAIR(1));
				makeBorder( 0, 0, this->getU(), this->getV() );
				attron(COLOR_PAIR(2));
				//attron(COLOR_PAIR(3));
				//makeBorder( this->getU()/2 - msg.size()/2 - 2, ((this->getV() - 1)/2)*this->getV()/this->getV() - 1, this->getU()/2 + msg.size()/2 + 3, ((this->getV() - 1)/2)*this->getV()/this->getV() + 2);
				//attroff(COLOR_PAIR(3));
				mvprintw( ((this->getV() - 1)/2 - 5)*this->getV()/this->getV(), this->getU()/2 - msg.size()/2 ,"%s", msg.c_str() );
				mvprintw( ((this->getV() - 1)/2 - 1)*this->getV()/this->getV(), this->getU()/2 - msg.size()/2 ,"Score: %d", this->getScore() );
				mvprintw( ((this->getV() - 1)/2 + 1)*this->getV()/this->getV(), this->getU()/2 - msg.size()/2 ,"Time:  %d", ptime );
				mvprintw( ((this->getV() - 1)/2 + 5)*this->getV()/this->getV(), this->getU()/2 - quit.size()/2 , quit.c_str() );
				attroff(COLOR_PAIR(2));
				attroff(COLOR_PAIR(1));
		}
	}
	refresh();
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

int 					Screen::getScore() const
{
	return (this->_score);
}

int 					Screen::getTime() const
{
	return (this->_time);
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

void					Screen::setScore( int const score )
{
	this->_score = score;
}

void					Screen::setTime( int const t )
{
	this->_time = t;
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