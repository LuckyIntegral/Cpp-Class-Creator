
#include "Point.hpp"

Point::Point() : _hello(DEFAULT_HELLO) {}
Point::Point( std::string hello ) : _hello(hello) {}
Point::Point( const Point &other ) : _hello(other._hello) {}
Point::~Point() {}

std::string Point::getHello( void ) const {
	return (this->_hello);
}

void Point::setHello( const std::string hello ) {
	this->_hello = hello;
}

Point &Point::operator=( const Point &other ) {
	this->_hello = other._hello;
	return (*this);
}
