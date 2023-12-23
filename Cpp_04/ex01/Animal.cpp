/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:10:45 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 01:27:06 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : _type( DEFAULT_TYPE ) {
    std::cout << "Animal: default constructor has been called" << std::endl;
}

Animal::Animal( const Animal &other ) {
    std::cout << "Animal: copy constructor has been called" << std::endl;
    *this = other;
}

Animal::~Animal() {
    std::cout << "Animal: destructor has been called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal: *silent*" << std::endl;
}

std::string Animal::getType() const {
    return (this->_type);
}

void    Animal::setType( std::string type ) {
    this->_type = type;
}

void Animal::announceIdea() const {
    std::cout << "Animal: clueless creature" << std::endl;
}

Animal &Animal::operator=( const Animal &other ) {
    std::cout << "Animal: copy assignment operator has been called" << std::endl;
    this->_type = other._type;
    return (*this);
}
