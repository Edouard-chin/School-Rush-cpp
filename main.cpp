/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:30:45 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 21:23:38 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"
#include "Monster.class.hpp"
#include "Shoot.class.hpp"
#include "Player.class.hpp"
#include "Entity.class.hpp"
#include <unistd.h>

void movePlayer(Player *player, char key);
void moveObjects(int posX, int posY, int color, char letter);
void fiiire(Shoot *shoot);


int main()
{
    Window  window;
    Monster megaMonster[20];
    Wall    walls[150];
    Player  player(0, 0);
    int     input        = 0;
    Shoot   shoot(-1, -1);

    while (input != Window::ESCAPE) {
        for (int i = 0; i < 30; i++) {
            megaMonster[i] -= 1;
            moveObjects(megaMonster[i].getPosX(), megaMonster[i].getPosY(), megaMonster[i].getColor(), megaMonster[i].getLetter());
        }
        moveObjects(player.getPosX(), player.getPosY(), player.getColor(), player.getLetter());
        input = wgetch(stdscr);
        erase();
        if (input == 261)
            player += 1;
        else if (input == 260)
            player -= 1;
        else if (input == 259)
            player + 1;
        else if (input == 258)
            player - 1;
        timeout(Window::DIFFICULTY);
    }

    return 0;
}

void moveObjects(int posX, int posY, int color, char letter)
{
    attron(COLOR_PAIR(color));
    mvprintw(posY, posX, "%c", letter);
    attroff(COLOR_PAIR(color));
}
