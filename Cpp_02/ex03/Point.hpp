/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:44:49 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 22:57:55 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point( const float x, const float b );
	Point( const Point &other );
	~Point();

	Point &operator=( const Point &other );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
};
