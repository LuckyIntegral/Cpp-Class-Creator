/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:24:37 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 17:58:40 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type( "Wrong Animal" ) {
    std::cout << "WrongAnimal: default constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other ) {
    std::cout << "WrongAnimal: copy constructor has been called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: destructor has been called" << std::endl;
}

void    WrongAnimal::setType(std::string type) {
    this->_type = type;
}

std::string WrongAnimal::getType() const {
    return (this->_type);
}

void    WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal: *silent*" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other ) {
    std::cout << "WrongAnimal: copy assignment operator has been called" << std::endl;
    this->_type = other.getType();
    return (*this);
}

