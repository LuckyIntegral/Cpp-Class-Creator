/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:26:49 by vfrants           #+#    #+#             */
/*   Updated: 2024/01/03 12:26:58 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    std::cout << "Dog: default constructor has been called" << std::endl;
    this->_type = TYPE_DOG;
}

Dog::Dog(const Dog &other) : Animal() {
    std::cout << "Dog: copy constructor has been called" << std::endl;
    this->_type = other._type;
}

Dog::~Dog() {
    std::cout << "Dog: destructor has been called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << this->_type << ": *woof*" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog: copy assignment operator has been called" << std::endl;
    this->_type = other._type;
    return (*this);
}
