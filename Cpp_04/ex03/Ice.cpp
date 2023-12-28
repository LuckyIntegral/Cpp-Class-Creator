
#include <iostream>

#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice") {
    // std::cout << "Ice: default constructor has been called" << std::endl;
}

Ice::Ice( const Ice &other ) : AMateria( other ) {
    // std::cout << "Ice: copy constructor has been called" << std::endl;
}

Ice::Ice( std::string const &type ) : AMateria( type ) {
	// std::cout << "Ice: constructor has been called" << std::endl;
}

Ice::~Ice() {
    // std::cout << "Ice: destructor has been called" << std::endl;
}

AMateria *Ice::clone( void ) const {
	return (new Ice( *this ));
}

void Ice::use( ICharacter &target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice &Ice::operator=( const Ice &other ) {
    // std::cout << "Ice: copy assignment operator has been called" << std::endl;
	this->_type = other._type;
    return (*this);
}
