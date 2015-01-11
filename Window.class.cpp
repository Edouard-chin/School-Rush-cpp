/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:28:26 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 03:30:43 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"
#include <stdlib.h>


const    int     Window::DIFFICULTY = 50;
const    int     Window::ESCAPE = 27;

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

void    Window::screenInit(int sizeX, int sizeY)
{
    initscr();
    noecho();
    raw();
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
