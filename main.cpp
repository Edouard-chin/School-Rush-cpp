/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:30:45 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 06:45:27 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"
#include "Monster.class.hpp"
#include "Shoot.class.hpp"
#include "Player.class.hpp"
#include <unistd.h>

void movePlayer(Player *player, char key);
void move(Monster *megaMonster);
void fiiire(Shoot *shoot);


int main()
{
    Window  window;
    Monster megaMonster[20];
    Player  player(0, 0);
    int     input        = 0;
    Shoot   shoot(-1, -1);

    while (input != Window::ESCAPE) {
        move(megaMonster);
        movePlayer(&player, 'X');
        input = wgetch(stdscr);
        erase();
        if (input == 261)
            movePlayer(&player, 'F');
        else if (input == 260)
            movePlayer(&player, 'B');
        else if (input == 259)
            movePlayer(&player, 'U');
        else if (input == 258)
            movePlayer(&player, 'D');
        else if (input == 32) {
            shoot.setPosX(player.getPosX());
            shoot.setPosY(player.getPosY());
            fiiire(&shoot);
        }

        timeout(Window::DIFFICULTY);
    }

    return 0;
}

void fiiire(Shoot *fiiire)
{
    attron(COLOR_PAIR(fiiire->getColor()));
    mvprintw(fiiire->getPosY(), fiiire->getPosX(), "%c", fiiire->getLetter());
    fiiire->setPosX(fiiire->getPosX() + 1);
    attroff(COLOR_PAIR(fiiire->getColor()));
}

void move(Monster *megaMonster)
{
    for (int i = 0; i < 30; i++)
    {
        attron(COLOR_PAIR(megaMonster[i].getColor()));
        mvprintw(megaMonster[i].getPosY(), megaMonster[i].getPosX(), "%c", megaMonster[i].getLetter());
        megaMonster[i] -= 1;
        attroff(COLOR_PAIR(megaMonster[i].getColor()));
    }
}

void movePlayer(Player *player, char key)
{
    if (key == 'F') {
        *player += 1;
    } else if (key == 'B') {
        *player -= 1;
    } else if (key == 'U') {
        *player + 1;
    } else if (key == 'D') {
        *player - 1;
    }
    attron(COLOR_PAIR(player->getColor()));
    mvprintw(player->getPosY(), player->getPosX(), "%c", player->getLetter());
    attroff(COLOR_PAIR(player->getColor()));
}
