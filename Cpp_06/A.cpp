
#include "A.hpp"

A::A() {}
A::A( const A &other ) {}
A::~A() {}

A &A::operator=( const A &other ) {
    return (*this);
}
