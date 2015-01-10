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
	Screen(void);					// taille par default 80 / 25
	Screen(int, int);				// taille en entree
	Screen(Screen const & src);
	virtual ~Screen(void);

	Screen				&operator=(Screen const & rhs);

	int					getU() const;
	int					getV() const;
	Squares *			getSquares() const;				// return first
	Squares *			getLastSquares(void) const;		// return the last
	Squares *			getPlayer() const;

	void				setU(int const u);
	void				setV(int const v);
	void				setSquares(Squares *);
	void				setPlayer(Squares *);

	void				initGame();

	void				printAll();

	Squares *			popSquares(Squares *);		// return the new first
	Squares *			pushSquares(Squares *);		// return the new last

	Squares *			killSquares(Squares *);		// delete and chain this Squares
													// return the prev square of delete one
	void				clearScreen();				// clear outside Squares in x only

	void				generateNewWalls();			// after clear, create wall in last X

	void				generateNewMonster();		// check how many M exists and create if need

	void				checkCollision();			// check all collisions
	Squares *			checkCollision(Squares *);	// check if one Square is in collision
													// return NULL or the ptr of collision
	int					newTurn();					// return keyboard

	void 				initTerm(int u, int v);
	void 				curses_print( int x, int y, char c, int color);
	int 				curses_input( void );

	// TODO changer nom deux fct ci dessus camelcase

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
	Squares	*			_squares;
	Squares *			_player;

};

std::ostream			&operator<<(std::ostream & o, Screen const & rhs);
std::ostream			&operator<<(std::ostream & o, Squares const * rhs);

#endif

/*
___

j'init avec une map de base

j'affiche le tout

on move le tout, car element vers la gauche, sauf player et shoot

on recree un nombre entre 1 et 3 cases en position MAX en haut et en bas

on check le nombre d'ennemis encore en vie pour en recreer si besoin

fct push new Squares

je parse chaque case voir si ca sort ou si die, ou si collision

si sort, x < 0, on refait le chainage en deletant proprement

*/