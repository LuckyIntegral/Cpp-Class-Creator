
#include "g.hpp"

#include <iostream>

g::g() {}
g::g( const g & ) {}
g::~g() {}

g &g::operator=( const g & ) {
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const g & ) {
	stream << "{g:{}}";
	return (stream);
}
