
#pragma once

#ifndef POINT_HPP
# define POINT_HPP

# include <string>

# define DEFAULT_HELLO

class Point {
protected:
	std::string	_hello;

public:
	Point();
	Point( std::string hello );
	Point( const Point &other );
	~Point();

	std::string getHello( void ) const;
	void setHello( const std::string hello );

    Point &operator=( const Point &other );
};

#endif // POINT_HPP
