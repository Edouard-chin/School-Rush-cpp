/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:30:45 by echin             #+#    #+#             */
/*   Updated: 2015/01/12 05:53:48 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"
#include <unistd.h>

bool collision(Object objects);

int main()
{
    Object  objects;
    Window  window;
    int     input        = 0;
    bool    dead         = false;
    objects.player       = new Player(0, 15);
    objects.i            = 0;

    while (input != Window::KEYESCAPE && !dead) {
        window.screenScrolling(&objects);
        input = wgetch(stdscr);
        erase();
        window.handleInput(input, objects.player, &objects.i, objects.shoot);
        dead = collision(objects);
        usleep(Window::DIFFICULTY * 540);
    }
    delete objects.player;
    window.gameOver(objects.player);

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
            return --*objects.player;
        }
    }
    for (int n = 0; n < 20; n++) {
        objectPosX = objects.monster[n].getPosX();
        if ((objectPosX == playerPosX || objectPosX - 1 == playerPosX || objectPosX + 1 == playerPosX) && objects.monster[n].getPosY() == playerPosY) {
            return --*objects.player;
        }
    }

    return false;
}
