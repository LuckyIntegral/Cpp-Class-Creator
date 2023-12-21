/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:34:41 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/20 15:48:09 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: _name("ClapTrap default"), _health(10), _energy(10), _damage(0)
{
	std::cout << "Default constructor is called" << std::endl;
}

ClapTrap::ClapTrap( const std::string name )
	: _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "Constructor is called" << std::endl;
}


ClapTrap::ClapTrap( const ClapTrap &other )
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor is called for '" << this->_name << "'" << std::endl;
}

void	ClapTrap::attack( const std::string &target )
{
	if (!this->_energy)
	{
		std::cout << "ClapTrap '" << this->_name
			<< "' ran out of energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap '" << this->_name << "' attacks '" << target
		<< "' causing '" << this->_damage <<  "' points of damage" << std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap '" << this->_name << "' takes '" << amount
		<< "' points of damage" << std::endl;
	this->_health -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (!this->_energy)
	{
		std::cout << "ClapTrap '" << this->_name
			<< "' ran out of energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap '" << this->_name << "' heals '" << amount
		<< "' points" << std::endl;
	this->_health += amount;
	this->_energy--;
}

void		ClapTrap::setName( const std::string name )
{
	this->_name = name;
}

void		ClapTrap::setHealth( const int points )
{
	this->_health = points;
}

void		ClapTrap::setEnergy( const int points )
{
	this->_energy = points;
}

void		ClapTrap::setDamage( const int points )
{
	this->_damage = points;
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

int			ClapTrap::getHealth( void ) const
{
	return (this->_health);
}

int			ClapTrap::getEnergy( void ) const
{
	return (this->_energy);
}

int			ClapTrap::getDamage( void ) const
{
	return (this->_damage);
}


ClapTrap &ClapTrap::operator=( const ClapTrap &other )
{
	std::cout << "Copy assignment operator is called" << std::endl;
	this->_name = other.getName();
	this->_health = other.getHealth();
	this->_energy = other.getEnergy();
	this->_damage = other.getDamage();
	return (*this);
}
