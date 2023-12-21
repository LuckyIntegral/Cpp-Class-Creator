/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:05:44 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/21 17:30:09 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: Default constructor is called" << std::endl;
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap( const std::string name ) : ClapTrap( name )
{
	std::cout << "FragTrap: Constructor is called" << std::endl;
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap( const FragTrap &other )
{
	std::cout << "FragTrap: Copy constructor is called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor is called for '" << this->_name
		<< "'" << std::endl;
}

void		FragTrap::attack( const std::string &target )
{
	if (!this->_energy)
	{
		std::cout << "FragTrap '" << this->_name
			<< "' ran out of energy" << std::endl;
		return ;
	}
	std::cout << "FragTrap '" << this->_name << "' attacks '" << target
		<< "' causing '" << this->_damage <<  "' points of damage" << std::endl;
	this->_energy--;
}

void		FragTrap::highFivesGuys( void )
{
	if (!this->_energy)
	{
		std::cout << "FragTrap '" << this->_name
			<< "' ran out of energy" << std::endl;
		return ;
	}
	std::cout << "FragTrap '" << this->_name
		<< "' give me high fives!" << std::endl;
	this->_energy--;
}

FragTrap	&FragTrap::operator=( const FragTrap &other )
{
	this->_name = other._name;
	this->_health = other._health;
	this->_damage = other._damage;
	this->_energy = other._energy;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const FragTrap &obj )
{
	stream << "FragTrap name '" << obj.getName() << '\''
		<< ", health: '" << obj.getHealth() << '\''
		<< ", energy: '" << obj.getEnergy() << '\''
		<< ", damage: '" << obj.getDamage() << '\'';
	return (stream);
}