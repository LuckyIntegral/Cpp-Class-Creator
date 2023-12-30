
#include <iostream>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat: default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) {
    std::cout << "Bureaucrat: copy constructor has been called" << std::endl;
    *this = other;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat: destructor has been called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other ) {
    std::cout << "Bureaucrat: copy assignment operator has been called" << std::endl;

    return (*this);
}

