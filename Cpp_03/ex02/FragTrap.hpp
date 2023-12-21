/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:54:30 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/21 17:05:36 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap( const std::string );
	FragTrap( const FragTrap &other );
	~FragTrap();

	void		attack( const std::string &target );
	void		highFivesGuys(void);

	FragTrap	&operator=( const FragTrap & );
};

std::ostream	&operator<<( std::ostream &stream, const FragTrap &obj );
