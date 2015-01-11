/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:30:45 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 03:52:33 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"
#include "Monster.class.hpp"
#include "Shoot.class.hpp"
#include <unistd.h>

int main()
{
    Window  window;
    Monster *megaMonster = new Monster(50, 0);
    Shoot   *shoot       = new Shoot(50, 10);
    int     input        = 0;

    while (input != Window::ESCAPE) {
        attron(COLOR_PAIR(megaMonster->getColor()));
        mvprintw(megaMonster->getPosY(), megaMonster->getPosX(), "%c", megaMonster->getLetter());
        mvprintw(shoot->getPosY(), shoot->getPosX(), "%c", shoot->getLetter());
        *megaMonster -= 1;
        attroff(COLOR_PAIR(megaMonster->getColor()));
        timeout(Window::DIFFICULTY);
        erase();
        input = wgetch(stdscr);
    }

    return 0;
}
