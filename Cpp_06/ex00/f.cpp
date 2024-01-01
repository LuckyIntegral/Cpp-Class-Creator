
#include <iostream>

#include "f.hpp"

f::f() {
    std::cout << "f: default constructor has been called" << std::endl;
}

f::f( const f &other ) {
    std::cout << "f: copy constructor has been called" << std::endl;
    *this = other;
}

f::~f() {
    std::cout << "f: destructor has been called" << std::endl;
}

f &f::operator=( const f &other ) {
    std::cout << "f: copy assignment operator has been called" << std::endl;

    return (*this);
}

