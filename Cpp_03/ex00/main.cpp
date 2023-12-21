/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:27:45 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/20 15:55:29 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main( void )
{
	ClapTrap	bob( "Bob" );

	bob.attack( "rat" );

	std::cout << "\nLog form main: " << bob.getName() << " has "
		<< bob.getHealth() << " points of health\n" << std::endl;

	bob.takeDamage( 7 );

	std::cout << "\nLog form main: " << bob.getName() << " has "
		<< bob.getHealth() << " points of health\n" << std::endl;

	bob.beRepaired( 10 );

	std::cout << "\nLog form main: " << bob.getName() << " has "
		<< bob.getHealth() << " points of health\n" << std::endl;

	for (int i = 0; i < 10; i++)
		bob.attack( "rat" );

	std::cout << "\nLog form main: " << bob.getName() << " has "
		<< bob.getEnergy() << " points of energy\n" << std::endl;

	return (0);
}
