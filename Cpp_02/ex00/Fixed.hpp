/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:35 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 16:49:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
private:
	int		_rawBits;
	static const int	_fractionalBits;

public:
	Fixed();
	Fixed( Fixed &other );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	Fixed	&operator=( const Fixed &other );
};