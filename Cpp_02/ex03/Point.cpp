/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:50:29 by vfrants           #+#    #+#             */
/*   Updated: 2023/12/19 23:00:49 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point( const float x, const float y ) : _x(0), _y(0) {}
Point::Point( const Point &other ) : _x(other.getX()), _y(other.getY()) {}
Point::~Point() {}


Point	&Point::operator=( const Point &other )
{
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}
