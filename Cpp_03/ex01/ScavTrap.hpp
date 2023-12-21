/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:58:25 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/21 16:53:50 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap( const std::string );
	ScavTrap( const ScavTrap &other );
	~ScavTrap();

	void		attack( const std::string &target );
	void		guardGate( void );

	ScavTrap	&operator=( const ScavTrap & );
};

std::ostream	&operator<<( std::ostream &stream, const ScavTrap &obj );
