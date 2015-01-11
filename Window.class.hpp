/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:30:21 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 03:29:38 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP
# include <iostream>
# include <ncurses.h>

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

    static const    int     DIFFICULTY;
    static const    int     ESCAPE;

private:
    int     _sizeX;
    int     _sizeY;

};

#endif // WINDOW_CLASS_HPP
