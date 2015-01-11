// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 11:06:32 by fbaudet-          #+#    #+#             //
//   Updated: 2015/01/10 11:06:32 by fbaudet-         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCREEN_CLASS_H
# define SCREEN_CLASS_H

# include "Squares.class.hpp"
# include "Monster.class.hpp"
# include "Player.class.hpp"
# include "Shoot.class.hpp"
# include "Wall.class.hpp"

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <ncurses.h>

class Screen {
public:
	Screen(void);
	Screen(int, int);
	Screen(Screen const & src);
	virtual ~Screen(void);

	Screen				&operator=(Screen const & rhs);

	int					getU() const;
	int					getV() const;
	int 				getScore() const;
	int 				getTime() const;
	Squares *			getSquares() const;
	Squares *			getLastSquares(void) const;
	Squares *			getPlayer() const;

	void				setU(int const u);
	void				setV(int const v);
	void				setScore(int const score);
	void				setTime(int const);
	void				setSquares(Squares *);
	void				setPlayer(Squares *);

	void				initGame();
	void				quitGame();

	Squares *			popSquares(Squares *);
	Squares *			pushSquares(Squares *);

	Squares *			killSquares(Squares *);

	int					newTurn();

	void				printAll();
	void				clearScreen();

	void				moveSquares(char const type);

	void				generateNewWalls();
	void				generateNewMonster();

	void				checkCollision();
	Squares *			checkCollision(Squares *) const;

	int					checkContinue(int) const;

	void 				initTerm( int u, int v );
	void 				cursesPrint( int x, int y, char c, int color );
	int 				cursesInput( void );
	
	void		 		printMenu( void );
	void				makeBorder( int xmin, int ymin, int xmax, int ymax );

	static const int 	ESC;
	static const int 	UP;
	static const int 	DOWN;
	static const int 	LEFT;
	static const int 	RIGHT;
	static const int 	ENTER;
	static const int 	SPACE;

private:
	int					_u;
	int					_v;
	int 				_score;
	int					_time;
	Squares	*			_squares;
	Squares *			_player;

};

std::ostream			&operator<<(std::ostream & o, Screen const & rhs);
std::ostream			&operator<<(std::ostream & o, Squares const * rhs);

#endif
