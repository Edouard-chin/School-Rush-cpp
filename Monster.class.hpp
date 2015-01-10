/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:00:09 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 16:37:17 by fbaudet-         ###   ########.fr       */
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
	Monster (Monster const &monster);
	Monster &operator=(Monster const &monster);

};

#endif
