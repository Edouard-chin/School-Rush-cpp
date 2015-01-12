/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:30:21 by echin             #+#    #+#             */
/*   Updated: 2015/01/12 06:02:36 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP
# include <iostream>
# include <ncurses.h>
# include "Player.class.hpp"
# include "Shoot.class.hpp"
# include "Monster.class.hpp"
# include "Wall.class.hpp"


struct Object {
   Wall    wall[20];
   Player  *player;
   Monster monster[20];
   Shoot   *shoot[40];
   int     i;
};

class Window
{

public:
    Window(void);
    virtual ~Window(void);
    Window(Window const & window);
    Window const & operator=(Window const & window);

    int     getSizeX(void) const;
    void    setSizeX(int    sizeX);
    int     getSizeY(void) const;
    void    setSizeY(int    sizeY);

    void    screenInit(int sizeX, int sizeY);
    void    moveObjects(int posX, int posY, int color, char letter, Player *player);
    void    handleInput(int input, Player *player, int *i, Shoot **shoot);
    void    screenScrolling(Object *objects);
    void    gameOver(Player *player);

    static const    int     DIFFICULTY;
    static const    int     KEYESCAPE;
    static const    int     KEYUP;
    static const    int     KEYDOWN;
    static const    int     KEYRIGHT;
    static const    int     KEYLEFT;
    static const    int     KEYSPACE;

private:
    int     _sizeX;
    int     _sizeY;

};

#endif // WINDOW_CLASS_HPP
