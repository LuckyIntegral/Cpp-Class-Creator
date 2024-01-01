#include <iostream>

#include "aa.hpp"

aa::aa() {}

aa::aa( const aa &other ) {*this = other;}

aa::~aa() {}

aa &aa::operator=( const aa &other ) {
    return (*this);
}

