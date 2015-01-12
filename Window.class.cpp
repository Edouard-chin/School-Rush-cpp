/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:28:26 by echin             #+#    #+#             */
/*   Updated: 2015/01/12 02:22:55 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"
#include <stdlib.h>


const    int     Window::DIFFICULTY = 50;
const    int     Window::KEYESCAPE = 27;
const    int     Window::KEYUP = 259;
const    int     Window::KEYRIGHT = 261;
const    int     Window::KEYDOWN = 258;
const    int     Window::KEYLEFT = 260;
const    int     Window::KEYSPACE = 32;

Window::Window(void) : _sizeX(100), _sizeY(30)
{
    this->screenInit(this->_sizeX, this->_sizeY);
}

Window::~Window(void)
{
    clear();
    endwin();
}

Window::Window(Window const & window) : _sizeX(window.getSizeX()), _sizeY(window.getSizeY())
{
    this->screenInit(window.getSizeX(), window.getSizeY());
}

Window const & Window::operator=(Window const & window)
{
    this->_sizeX = window.getSizeX();
    this->_sizeY = window.getSizeY();

    return window;
}

void    Window::screenInit(int sizeX, int sizeY)
{
    initscr();
    noecho();
    raw();
    nodelay(stdscr,TRUE);
    keypad(stdscr, TRUE);
    if (getenv("ESCDELAY") == NULL) {
        ESCDELAY = 1;
    }
    curs_set(0);
    resizeterm(sizeY, sizeX);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
}

void    Window::moveObjects(int posX, int posY, int color, char letter)
{
    attron(COLOR_PAIR(color));
    mvprintw(posY, posX, "%c", letter);
    attroff(COLOR_PAIR(color));
}

void    Window::handleInput(int input, Player *player, int *i, Shoot **shoot)
{
    if (input == Window::KEYRIGHT) {
        *player += 1;
    } else if (input == Window::KEYLEFT) {
        *player -= 1;
    } else if (input == Window::KEYUP) {
        *player + 1;
    } else if (input == Window::KEYDOWN) {
        *player - 1;
    } else if (input == Window::KEYSPACE) {
        if (*i == 40) {
            *i = 0;
            shoot[*i]->setPosX(player->getPosX() + 1);
            shoot[*i]->setPosY(player->getPosY());
        } else {
            shoot[*i] = new Shoot(player->getPosX() + 1, player->getPosY());
        }
        *i = *i + 1;
    }
}



int     Window::getSizeX(void) const
{
    return this->_sizeX;
}

void    Window::setSizeX(int    sizeX)
{
    this->_sizeX = sizeX;
}

int     Window::getSizeY(void) const
{
    return this->_sizeY;
}

void    Window::setSizeY(int    sizeY)
{
    this->_sizeY = sizeY;
}

