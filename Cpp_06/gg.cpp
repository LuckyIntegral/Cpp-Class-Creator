#include <iostream>

#include "gg.hpp"

gg::gg() 
    : _number(DEFAULT_NUMBER), _numbers(DEFAULT_NUMBERS) {}
gg::gg( int number, int numbers)
    : _number(number), _numbers(numbers) {}
gg::gg( const gg &other )
    : _number(other._number), _numbers(other._numbers) {}
gg::~gg() {}


int gg::getNumber( void ) const {
	return (this->_number);
}

void gg::setNumber( const int number ) {
	this->_number = number;
}

int gg::getNumbers( void ) const {
	return (this->_numbers);
}

void gg::setNumbers( const int numbers ) {
	this->_numbers = numbers;
}

gg &gg::operator=( const gg &other ) {
    return (*this);
}

