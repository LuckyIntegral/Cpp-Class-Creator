/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:38:25 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 12:42:12 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal() {
    std::cout << "Cat: default constructor has been called" << std::endl;
    this->_type = TYPE_CAT;
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat: copy constructor has been called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat: destructor has been called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << this->_type << ": *meow*" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat: copy assignment operator has been called" << std::endl;
    this->_type = other._type;
    return (*this);
}

