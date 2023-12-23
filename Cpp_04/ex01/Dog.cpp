/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:26:49 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 12:32:09 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal() {
    std::cout << "Dog: default constructor has been called" << std::endl;
    this->_type = TYPE_DOG;
    this->_brain = new Brain();
}

Dog::Dog( const Dog &other ) {
    std::cout << "Dog: copy constructor has been called" << std::endl;
    *this = other;
}

Dog::~Dog() {
    std::cout << "Dog: destructor has been called" << std::endl;
    delete (this->_brain);
}

void Dog::makeSound( void ) const {
    std::cout << this->_type << ": *woof*" << std::endl;
}

void Dog::announceIdea( void ) const {
    std::cout << this->_brain->getRandomIdea() << std::endl;
}

Dog &Dog::operator=( const Dog &other ) {
    std::cout << "Dog: copy assignment operator has been called" << std::endl;
    this->_type = other._type;
    this->_brain = other._brain;
    return (*this);
}
