#include "HumanB.hpp"

HumanB::HumanB( std::string &name, Weapon *weapon = NULL)
	: _name(name), _weapon(weapon) {}
HumanB::~HumanB() {}

void	HumanB::attack( void ) const
{

}

Weapon	HumanB::getWeapon( void ) const
{
	return (*this->_weapon);
}
