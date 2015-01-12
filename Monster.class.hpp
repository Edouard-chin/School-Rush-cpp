/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:19:30 by echin             #+#    #+#             */
/*   Updated: 2015/01/12 03:44:08 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_CLASS_HPP
# define MONSTER_CLASS_HPP
# include "Entity.class.hpp"

class Monster : public Entity
{

    public:
        Monster(void);
        ~Monster(void);
        Monster(Monster const & monster);
        Monster const &operator=(Monster const & monster);

};
Monster &operator-=(Monster &monster, int n);
#endif
