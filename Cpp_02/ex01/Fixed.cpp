/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:35:03 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 20:36:05 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

// static first
const int	Fixed::_fractionalBits = 8;

// init part
Fixed::Fixed( void ): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed( const int number )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(number << this->_fractionalBits);
}

Fixed::Fixed( const float number )
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(number * (1 << this->_fractionalBits)));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

// methods
int	Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->_fractionalBits);
}

float	Fixed::toFloat( void ) const
{
	return (float)(this->getRawBits()) / (1 << this->_fractionalBits);
}

// operators
Fixed	&Fixed::operator=( const Fixed &other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = other.getRawBits();
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Fixed &point )
{
	stream << point.toFloat();
	return (stream);
}
