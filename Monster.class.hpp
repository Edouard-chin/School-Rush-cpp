/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:00:09 by echin             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/10 16:37:17 by fbaudet-         ###   ########.fr       */
=======
/*   Updated: 2015/01/10 16:54:17 by echin            ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_CLASS_HPP
# define MONSTER_CLASS_HPP
# include "Entity.class.hpp"

class Monster : public Entity
{

public:
	Monster(void);
	virtual ~Monster(void);
	Monster (Monster const &monster);
	Monster const &operator=(Monster const &monster);

};

#endif
