/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:05:57 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 15:15:17 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_CLASS_HPP
# define SHOOT_CLASS_HPP
# include "Entity.class.hpp"

class Shoot : public Entity
{

public:
	Shoot(void);
	~Shoot(void);
	Shoot (Shoot const &shoot);
	Shoot &operator=(Shoot const &shoot);
	int		getDamage(void) const;
	void	setDamage(int damage);

protected:
	int	_damage;
};

#endif