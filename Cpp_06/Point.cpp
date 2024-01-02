
#include "Point.hpp"

Point::Point() : _x(DEFAULT_X), _y(DEFAULT_Y), _z(DEFAULT_Z) {}
Point::Point( float x, float y, float z ) : _x(x), _y(y), _z(z) {}
Point::Point( const Point &other ) : _x(other._x), _y(other._y), _z(other._z) {}
Point::~Point() {}

float Point::getX( void ) const {
	return (this->_x);
}

void Point::setX( const float x ) {
	this->_x = x;
}

float Point::getY( void ) const {
	return (this->_y);
}

void Point::setY( const float y ) {
	this->_y = y;
}

float Point::getZ( void ) const {
	return (this->_z);
}

void Point::setZ( const float z ) {
	this->_z = z;
}

Point &Point::operator=( const Point &other ) {
    return (*this);
}
