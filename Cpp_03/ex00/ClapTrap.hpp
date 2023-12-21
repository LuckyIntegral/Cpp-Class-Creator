/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:28:00 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/20 13:47:50 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap
{
private:
	std::string	_name;
	int			_health;
	int			_energy;
	int			_damage;

public:
	ClapTrap();
	ClapTrap( const std::string );
	ClapTrap( const ClapTrap &other );
	~ClapTrap();

	void	attack( const std::string &target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	void		setName( const std::string name );
	void		setHealth( const int points );
	void		setEnergy( const int points );
	void		setDamage( const int points );
	std::string	getName( void ) const;
	int			getHealth( void ) const;
	int			getEnergy( void ) const;
	int			getDamage( void ) const;

	ClapTrap &operator=( const ClapTrap &other );
};
