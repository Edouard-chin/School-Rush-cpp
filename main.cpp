/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:30:45 by echin             #+#    #+#             */
/*   Updated: 2015/01/12 00:57:33 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"
#include "Monster.class.hpp"
#include "Shoot.class.hpp"
#include "Wall.class.hpp"
#include "Player.class.hpp"
#include "Entity.class.hpp"
#include <unistd.h>
#include <stdlib.h>


struct Object {
   Wall    wall[20];
   Player  *player;
   Monster monster[20];
   Shoot   *shoot[40];
   int     i;
};

void moveObjects(int posX, int posY, int color, char letter);
bool collision(Object objects);


int main()
{
    Object  objects;
    Window  window;
    int     input        = 0;
    bool    dead         = false;
    objects.player       = new Player(0, 15);
    objects.i            = 0;

    while (input != Window::ESCAPE && !dead) {
        for (int i = 0; i < 20; i++) {
            objects.wall[i] -= 1;
            moveObjects(objects.wall[i].getPosX(), objects.wall[i].getPosY(), objects.wall[i].getColor(), objects.wall[i].getLetter());
        }
        for (int n = 0; n < 20; n++) {
            objects.monster[n] -= 1;
            moveObjects(objects.monster[n].getPosX(), objects.monster[n].getPosY(), objects.monster[n].getColor(), objects.monster[n].getLetter());
        }
        for (int n = 0; n < objects.i; n++) {
            *objects.shoot[n] += objects.monster;
            moveObjects(objects.shoot[n]->getPosX(), objects.shoot[n]->getPosY(), objects.shoot[n]->getColor(), objects.shoot[n]->getLetter());
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
        else if (input == 32) {
            if (objects.i == 40) {
                objects.i = 0;
            }
            objects.shoot[objects.i] = new Shoot(objects.player->getPosX() + 1, objects.player->getPosY());
            objects.i++;
        }

        dead = collision(objects);
        usleep(27000);
    }

    delete objects.player;

    return 0;
}

bool  collision(Object objects)
{
    int playerPosX = objects.player->getPosX();
    int playerPosY = objects.player->getPosY();
    int objectPosX = 0;

    for (int i = 0; i < 20; i++) {
        objectPosX = objects.wall[i].getPosX();
        if ((objectPosX == playerPosX || objectPosX - 1 == playerPosX || objectPosX + 1 == playerPosX) && objects.wall[i].getPosY() == playerPosY) {
            return true;
        }
    }
    for (int n = 0; n < 20; n++) {
        objectPosX = objects.monster[n].getPosX();
        if ((objectPosX == playerPosX || objectPosX - 1 == playerPosX || objectPosX + 1 == playerPosX) && objects.monster[n].getPosY() == playerPosY) {
            return true;
        }
    }

    return false;
}

void moveObjects(int posX, int posY, int color, char letter)
{
    attron(COLOR_PAIR(color));
    mvprintw(posY, posX, "%c", letter);
    attroff(COLOR_PAIR(color));
}
