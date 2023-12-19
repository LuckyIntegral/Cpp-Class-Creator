/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:35 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 22:27:02 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>

class Fixed
{
private:
	int		_rawBits;
	static const int	_fractionalBits;

public:
	Fixed();
	Fixed( const Fixed &other );
	Fixed( const int number );
	Fixed( const float number );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;

	Fixed	&operator=( const Fixed &other );

	bool	operator==( const Fixed &other ) const;
	bool	operator!=( const Fixed &other ) const;
	bool	operator<=( const Fixed &other ) const;
	bool	operator>=( const Fixed &other ) const;
	bool	operator>( const Fixed &other ) const;
	bool	operator<( const Fixed &other ) const;

	Fixed	operator*( const Fixed &other );
	Fixed	operator/( const Fixed &other );
	Fixed	operator+( const Fixed &other );
	Fixed	operator-( const Fixed &other );

	Fixed	operator++( int );
	Fixed	&operator++( void );
	Fixed	operator--( int );
	Fixed	&operator--( void );

	static const Fixed	&max( const Fixed &a, const Fixed &b);
	static Fixed	&max( Fixed &a, Fixed &b);
	static const Fixed	&min( const Fixed &a, const Fixed &b);
	static Fixed	&min( Fixed &a, Fixed &b);
};

std::ostream	&operator<<( std::ostream &stream, const Fixed &point );
