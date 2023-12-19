/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:35:03 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 17:03:33 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// static first
const int	Fixed::_fractionalBits = 8;

Fixed::Fixed( void ): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed &other )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = other.getRawBits();
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( const Fixed &other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}
