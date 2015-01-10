/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echin <echin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:37:54 by echin             #+#    #+#             */
/*   Updated: 2015/01/10 15:05:16 by echin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_CLASS_HPP
# define ENTITY_CLASS_HPP
# include <iostream>

class Entity
{

public:
	Entity(char letter, int velocity, int color, int mhp, int chp);
	~Entity(void);
	Entity(Entity const &entity);
	Entity &operator=(Entity const &entity);
	char		getLetter(void) const;
	void		setLetter(char letter);
	int			getVelocity(void) const;
	void		setVelocity(int velocity);
	int 		getColor(void) const;
	void		setColor(int color);
	int			getMhp(void) const;
	void		setMhp(int mhp);
	int			getChp(void) const;
	void		setChp(int chp);

	static const	char		MONSTER;
	static const 	char 		PLAYER;
	static const 	char 		WALL;
	static const 	char 		SHOOT;
	static const	int			RED;
	static const	int			GREEN;
	static const	int			BLUE;

protected:
	char		_letter;
	int			_velocity;
	int         _color;
	int			_mhp;
	int			_chp;

};

#endif