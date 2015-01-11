/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:49:35 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 05:39:51 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_CLASS_HPP
# define ENTITY_CLASS_HPP
# include <iostream>

class Entity
{

public:
    Entity(char letter, int velocity, int color, int mhp, int chp, int posX, int posY);
    virtual ~Entity(void);
    Entity(Entity const &entity);
    Entity const &operator=(Entity const &entity);
    char        getLetter(void) const;
    void        setLetter(char letter);
    int         getVelocity(void) const;
    void        setVelocity(int velocity);
    int         getColor(void) const;
    void        setColor(int color);
    int         getMhp(void) const;
    void        setMhp(int mhp);
    int         getChp(void) const;
    void        setChp(int chp);
    int         getPosX(void) const;
    void        setPosX(int posX);
    int         getPosY(void) const;
    void        setPosY(int posY);
    void        die();
    int         generateCoordinate(int min, int max);


    static const    char        MONSTER;
    static const    char        PLAYER;
    static const    char        WALL;
    static const    char        SHOOT;
    static const    int         RED;
    static const    int         GREEN;
    static const    int         BLUE;

protected:
    char        _letter;
    int         _velocity;
    int         _color;
    int         _mhp;
    int         _chp;
    int         _posX;
    int         _posY;

};

#endif
