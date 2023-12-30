
#include <iostream>

#include "Form.hpp"

Form::Form() {
    std::cout << "Form: default constructor has been called" << std::endl;
}

Form::Form( const Form &other ) {
    std::cout << "Form: copy constructor has been called" << std::endl;
    *this = other;
}

Form::~Form() {
    std::cout << "Form: destructor has been called" << std::endl;
}

Form &Form::operator=( const Form &other ) {
    std::cout << "Form: copy assignment operator has been called" << std::endl;

    return (*this);
}

