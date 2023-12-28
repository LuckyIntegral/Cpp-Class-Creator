
#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type( "undefined_materia" ) {
    // std::cout << "AMateria: default constructor has been called" << std::endl;
}

AMateria::AMateria( const AMateria &other ) {
    // std::cout << "AMateria: copy constructor has been called" << std::endl;
    *this = other;
}

AMateria::~AMateria( void ) {
    // std::cout << "AMateria: destructor has been called" << std::endl;
}

AMateria::AMateria( std::string const &type ) : _type( type ) {
	// std::cout << "AMateria: constructor has been called" << std::endl;
}

std::string const &AMateria::getType( void ) const {
	return (this->_type);
}

void AMateria::use( ICharacter &target ) {
	std::cout << "AMateria: dont know how to use 'use' funstion for abstract class" << std::endl;
	(void) target;
}

AMateria &AMateria::operator=( const AMateria &other ) {
    // std::cout << "AMateria: copy assignment operator has been called" << std::endl;
	this->_type = other._type;
    return (*this);
}
