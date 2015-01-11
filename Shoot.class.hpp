/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:36:25 by echin             #+#    #+#             */
/*   Updated: 2015/01/11 23:54:38 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_CLASS_HPP
# define SHOOT_CLASS_HPP
# include "Entity.class.hpp"
# include "Monster.class.hpp"

class Shoot : public Entity
{

public:
    Shoot(int posX, int posY);
    virtual ~Shoot(void);
    Shoot (Shoot const &shoot);
    Shoot const &operator=(Shoot const &shoot);
    int     getDamage(void) const;
    void    setDamage(int damage);
    int     getNumber(void) const;

protected:
    int _damage;
};

Shoot &operator+=(Shoot &shoot, Monster *monster);


#endif
