/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:28:00 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/21 17:25:17 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>

class ClapTrap
{
protected:
	std::string	_name;
	int			_health;
	int			_energy;
	int			_damage;

public:
	ClapTrap();
	ClapTrap( const std::string );
	ClapTrap( const ClapTrap &other );
	virtual ~ClapTrap();

	virtual void	attack( const std::string &target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	virtual void		setName( const std::string name );
	virtual void		setHealth( const int points );
	virtual void		setEnergy( const int points );
	virtual void		setDamage( const int points );
	virtual std::string	getName( void ) const;
	virtual int			getHealth( void ) const;
	virtual int			getEnergy( void ) const;
	virtual int			getDamage( void ) const;

	virtual ClapTrap	&operator=( const ClapTrap &other );
};

std::ostream	&operator<<( std::ostream &stream, const ClapTrap &point );
