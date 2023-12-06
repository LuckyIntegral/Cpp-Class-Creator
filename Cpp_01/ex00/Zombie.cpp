#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void )
{
	this->_name = "Default Morty";
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": Died because of starving..." << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}

std::string	Zombie::getName( void ) const
{
	return (this->_name);
}
