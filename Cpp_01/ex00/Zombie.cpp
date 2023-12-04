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

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
