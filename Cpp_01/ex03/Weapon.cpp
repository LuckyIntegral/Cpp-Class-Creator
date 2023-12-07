#include "Weapon.hpp"

Weapon::Weapon(): _type(DEFAULT_TYPE) { }
Weapon::Weapon( const std::string type ): _type(type) { }
Weapon::~Weapon( ) { }

const std::string	&Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType( const std::string type )
{
	this->_type =type;
}
