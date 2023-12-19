/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:35 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 18:02:46 by vfrants          ###   ########.fr       */
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
};

std::ostream	&operator<<( std::ostream &stream, const Fixed &point );
