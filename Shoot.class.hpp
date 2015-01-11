/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:05:57 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 12:54:33 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_CLASS_HPP
# define SHOOT_CLASS_HPP
# include "AEntity.class.hpp"

class Shoot : public AEntity
{

public:
	Shoot(void);
	virtual ~Shoot(void);
	Shoot (Shoot const &shoot);
	Shoot const &operator=(Shoot const &shoot);
	int		getDamage(void) const;
	void	setDamage(int damage);

	char		die();

private:
	int	_damage;
};

#endif