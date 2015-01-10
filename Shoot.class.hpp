/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:05:57 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 17:15:23 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_CLASS_HPP
# define SHOOT_CLASS_HPP
# include "Entity.class.hpp"

class Shoot : public Entity
{

public:
	Shoot(void);
	virtual ~Shoot(void);
	Shoot (Shoot const &shoot);
	Shoot const &operator=(Shoot const &shoot);
	int		getDamage(void) const;
	void	setDamage(int damage);

protected:
	int	_damage;
};

#endif