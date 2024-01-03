
#include "Point.hpp"

Point::Point() : _x(DEFAULT_X), _y(DEFAULT_Y), _z(DEFAULT_Z) {}
Point::Point( int x, int y, std::string z ) : _x(x), _y(y), _z(z) {}
Point::Point( const Point &other ) : _x(other._x), _y(other._y), _z(other._z) {}
Point::~Point() {}

int Point::getX( void ) const {
	return (this->_x);
}

void Point::setX( const int x ) {
	this->_x = x;
}

int Point::getY( void ) const {
	return (this->_y);
}

void Point::setY( const int y ) {
	this->_y = y;
}

std::string Point::getZ( void ) const {
	return (this->_z);
}

void Point::setZ( const std::string z ) {
	this->_z = z;
}

Point &Point::operator=( const Point &other ) {
	this->_x = other._x;
	this->_y = other._y;
	this->_z = other._z;
	return (*this);
}
