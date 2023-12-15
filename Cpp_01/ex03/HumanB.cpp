
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name )
	: _weapon(NULL), _name(name) {}
HumanB::~HumanB() {}

void	HumanB::attack( void ) const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their "
			<< DEFAULT_WEAPON << std::endl;
}

Weapon	HumanB::getWeapon( void ) const
{
	return (*this->_weapon);
}

std::string	HumanB::getName( void ) const
{
	return (this->_name);
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}

void	HumanB::setName( const std::string &name )
{
	this->_name = name;
}