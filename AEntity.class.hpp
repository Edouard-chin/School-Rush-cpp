/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaudet- <fbaudet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:37:54 by aribon            #+#    #+#             */
/*   Updated: 2015/01/11 13:25:55 by fbaudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ENTITY_CLASS_HPP
# define A_ENTITY_CLASS_HPP
# include <iostream>

class AEntity
{
public:
	AEntity(char letter, int velocity, int color, int mhp, int chp);
	virtual ~AEntity(void);
	AEntity(AEntity const &entity);
	AEntity const &operator=(AEntity const &entity);
	char		getLetter(void) const;
	void		setLetter(char const letter);
	int			getVelocity(void) const;
	void		setVelocity(int const velocity);
	int 		getColor(void) const;
	void		setColor(int const color);
	int			getMhp(void) const;
	void		setMhp(int const mhp);
	int			getChp(void) const;
	void		setChp(int const chp);

	virtual char		die() = 0;

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

private:
	AEntity(void);

};

#endif