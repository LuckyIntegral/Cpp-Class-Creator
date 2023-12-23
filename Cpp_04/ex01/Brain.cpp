/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:48:58 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/23 21:57:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: default constructor has been called" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = std::string("This is mine idea number ").append( std::to_string(i) );
}

Brain::Brain( const Brain &other ) {
    std::cout << "Brain: copy constructor has been called" << std::endl;
    *this = other;
}

Brain::~Brain() {
    std::cout << "Brain: destructor has been called" << std::endl;
}

std::string Brain::getRandomIdea() const {
    return (this->_ideas[std::time(NULL) % 100]);
}

Brain &Brain::operator=( const Brain &other ) {
    std::cout << "Brain: copy assignment operator has been called" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = other._ideas[i];
    return (*this);
}

