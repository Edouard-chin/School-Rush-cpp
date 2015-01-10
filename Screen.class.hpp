// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Screen.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 11:06:32 by fbaudet-          #+#    #+#             //
//   Updated: 2015/01/10 11:06:32 by fbaudet-         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCREEN_H
# define SCREEN_H

# include "Squares.class.hpp"
# include "Monster.class.hpp"
# include "Player.class.hpp"
# include "Shoot.class.hpp"
# include "Wall.class.hpp"

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

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

	void				setU(int const u);
	void				setV(int const v);
	void				setSquares(Squares * s);

	void				initGame();

	void				printAll();

	Squares *			popSquares(Squares *);		// return the new first
	Squares *			pushSquares(Squares *);		// return the new last

	Squares *			killSquares(Squares *);		// delete and chain this Squares
													// return the prev square of delete one
	void				clearScreen();				// clear outside Squares in x only

	void				generateNewWalls();			// after clear, create wall in last X

	int					generateNewMonster();		// check how many M exists and create if need

	/*
	**	collision, on check d'abord le player
	*/
	void				checkCollision();			// check all collisions
	Squares *			checkCollision(Squares *);	// check if one Square is in collision
													// return NULL or the ptr of collision

	void				newTurn();

	// fonction init de ncurses

private:
	int					_u;			// taille largeur
	int					_v;			// taille hauteur
	Squares	*			_squares;	// tableau de squares en fixe

};

std::ostream			&operator<<(std::ostream & o, Screen const & rhs);

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