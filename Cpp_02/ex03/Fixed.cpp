/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:35:03 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 22:33:41 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

// static first
const int	Fixed::_fractionalBits = 8;

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::min( Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

// init part
Fixed::Fixed( void ): _rawBits(0) {}

Fixed::Fixed( const Fixed &other )
{
	*this = other;
}

Fixed::Fixed( const int number ) : _rawBits(number << this->_fractionalBits) {}

Fixed::Fixed( const float number )
	: _rawBits(roundf(number * (1 << this->_fractionalBits))) {}

Fixed::~Fixed( void ) {}

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
	this->_rawBits = other.getRawBits();
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Fixed &point )
{
	stream << point.toFloat();
	return (stream);
}

// bool part
bool	Fixed::operator==( const Fixed &other ) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=( const Fixed &other ) const
{
	return (this->getRawBits() != other.getRawBits());
}

bool	Fixed::operator<=( const Fixed &other ) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>=( const Fixed &other ) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator>( const Fixed &other ) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<( const Fixed &other ) const
{
	return (this->getRawBits() < other.getRawBits());
}

// arithmetic part
Fixed	Fixed::operator*( const Fixed &other )
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator+( const Fixed &other )
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator/( const Fixed &other )
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	Fixed::operator-( const Fixed &other )
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

// increments
Fixed	Fixed::operator++( int )
{
	Fixed	dup(*this);
	this->_rawBits++;
	return (dup);
}

Fixed	&Fixed::operator++( void ) // preincrement
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	dup(*this);
	this->_rawBits--;
	return (dup);
}

Fixed	&Fixed::operator--( void ) // predecrement
{
	this->_rawBits--;
	return (*this);
}
