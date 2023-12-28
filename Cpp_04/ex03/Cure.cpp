
#include <iostream>

#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure") {
    // std::cout << "Cure: default constructor has been called" << std::endl;
}

Cure::Cure( const Cure &other ) : AMateria( other ) {
    // std::cout << "Cure: copy constructor has been called" << std::endl;
}

Cure::Cure( std::string const &type ) : AMateria( type ) {
	// std::cout << "Cure: constructor has been called" << std::endl;
}

Cure::~Cure() {
    // std::cout << "Cure: destructor has been called" << std::endl;
}

AMateria *Cure::clone( void ) const {
	return (new Cure( *this ));
}

void Cure::use( ICharacter &target ) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure &Cure::operator=( const Cure &other ) {
    // std::cout << "Cure: copy assignment operator has been called" << std::endl;
	this->_type = other._type;
    return (*this);
}
