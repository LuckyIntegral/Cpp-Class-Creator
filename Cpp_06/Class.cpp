
#include "Class.hpp"

#include <iostream>

Class::Class() {}
Class::Class( const Class & ) {}
Class::~Class() {}

Class &Class::operator=( const Class & ) {
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Class & ) {
	stream << "{Class:{}}";
	return (stream);
}
