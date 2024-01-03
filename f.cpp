
#include "f.hpp"

#include <iostream>

f::f() : _g(DEFAULT_G) {}
f::f( int g ) : _g(g) {}
f::f( const f &other ) : _g(other._g) {}
f::~f() {}

int f::getG( void ) const {
	return (this->_g);
}

void f::setG( const int g ) {
	this->_g = g;
}

f &f::operator=( const f &other ) {
	this->_g = other._g;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const f &instance ) {
	stream << "{f:"
		<< "g=" << instance.getG() << '}';
	return (stream);
}
