/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:19:30 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 03:08:15 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_CLASS_HPP
# define MONSTER_CLASS_HPP
# include "Entity.class.hpp"

class Monster : public Entity
{

    public:
        Monster(int posX, int posY);
        ~Monster();
        Monster(Monster const & monster);
        Monster const &operator=(Monster const & monster);

};
Monster &operator-=(Monster &monster, int n);

#endif
