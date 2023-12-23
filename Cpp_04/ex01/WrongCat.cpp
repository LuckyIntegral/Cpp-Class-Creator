/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:58:45 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 22:58:44 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat: default constructor has been called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal() {
    std::cout << "WrongCat: copy constructor has been called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: destructor has been called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat: *meow*" << std::endl;
}

WrongCat &WrongCat::operator=( const WrongCat &other ) {
    std::cout << "WrongCat: copy assignment operator has been called" << std::endl;
    this->_type = other.getType();
    return (*this);
}
