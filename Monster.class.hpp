/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:00:09 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 13:23:57 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_CLASS_HPP
# define MONSTER_CLASS_HPP
# include "AEntity.class.hpp"

class Monster : public AEntity
{

public:
	Monster(void);
	virtual ~Monster(void);
	Monster (Monster const &monster);
	Monster const &operator=(Monster const &monster);

	char		die();

};

#endif
