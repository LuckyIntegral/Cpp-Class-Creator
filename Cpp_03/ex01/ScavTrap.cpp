/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:34:46 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/21 17:30:17 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap: Default constructor is called" << std::endl;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap( const std::string name ) : ClapTrap( name )
{
	std::cout << "ScavTrap: Constructor is called" << std::endl;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &other )
{
	std::cout << "ScavTrap: Copy constructor is called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor is called for '" << this->_name
		<< "'" << std::endl;
}

void		ScavTrap::attack( const std::string &target )
{
	if (!this->_energy)
	{
		std::cout << "ScavTrap '" << this->_name
			<< "' ran out of energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap '" << this->_name << "' attacks '" << target
		<< "' causing '" << this->_damage <<  "' points of damage" << std::endl;
	this->_energy--;
}

void		ScavTrap::guardGate( void )
{
	if (!this->_energy)
	{
		std::cout << "ScavTrap '" << this->_name
			<< "' ran out of energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap '" << this->_name
		<< "' is now in Gate keeper mode" << std::endl;
	this->_energy--;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &other )
{
	this->_name = other._name;
	this->_health = other._health;
	this->_damage = other._damage;
	this->_energy = other._energy;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const ScavTrap &obj )
{
	stream << "ScavTrap name '" << obj.getName() << '\''
		<< ", health: '" << obj.getHealth() << '\''
		<< ", energy: '" << obj.getEnergy() << '\''
		<< ", damage: '" << obj.getDamage() << '\'';
	return (stream);
}