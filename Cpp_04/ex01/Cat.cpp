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
    this->_brain = new Brain();
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat: copy constructor has been called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat: destructor has been called" << std::endl;
    delete (this->_brain);
}

void Cat::makeSound() const {
    std::cout << this->_type << ": *meow*" << std::endl;
}

void Cat::announceIdea() const {
    std::cout << this->_brain->getRandomIdea() << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat: copy assignment operator has been called" << std::endl;
    this->_type = other._type;
    this->_brain = other._brain;
    return (*this);
}

