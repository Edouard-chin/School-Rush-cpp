/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:30:45 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 21:59:48 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"
#include "Monster.class.hpp"
#include "Shoot.class.hpp"
#include "Wall.class.hpp"
#include "Player.class.hpp"
#include "Entity.class.hpp"
#include <unistd.h>

void movePlayer(Player *player, char key);
void moveObjects(int posX, int posY, int color, char letter);
void fiiire(Shoot *shoot);

struct Babibel {
   Wall wall[150];
   Player *player;
   Monster monster[20];
   Shoot *shoot;
};


int main()
{
    Babibel objects;
    Window  window;
    // Monster megaMonster[20];
    // Wall    walls[150];
    // Player  player(0, 0);
    // Shoot   shoot(-1, -1);
    int     input        = 0;

    objects.player = new Player(0, 0);
    objects.player->setPosX(0);
    objects.player->setPosY(0);
    while (input != Window::ESCAPE) {
        for (int i = 0; i < 150; i++) {
            objects.wall[i] -= 1;
            moveObjects(objects.wall[i].getPosX(), objects.wall[i].getPosY(), objects.wall[i].getColor(), objects.wall[i].getLetter());
        }
        for (int n = 0; n < 20; n++) {
            objects.monster[n] -= 1;
            moveObjects(objects.monster[n].getPosX(), objects.monster[n].getPosY(), objects.monster[n].getColor(), objects.monster[n].getLetter());
        }
        moveObjects(objects.player->getPosX(), objects.player->getPosY(), objects.player->getColor(), objects.player->getLetter());
        input = wgetch(stdscr);
        erase();
        if (input == 261)
            *objects.player += 1;
        else if (input == 260)
            *objects.player -= 1;
        else if (input == 259)
            *objects.player + 1;
        else if (input == 258)
            *objects.player - 1;
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
