
#include <iostream>

#include "Number.hpp"

Number::Number() {}
Number::Number( const Number &other ) {*this = other;}
Number::~Number() {}

int Number::getFloating_pint_number( void ) const {
	return (this->_floating_pint_number);
}

void Number::setFloating_pint_number( const int floating_pint_number ) {
	this->_floating_pint_number = floating_pint_number;
}

Number &Number::operator=( const Number &other ) {
    return (*this);
}

