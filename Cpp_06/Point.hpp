
#pragma once

#ifndef POINT_HPP
# define POINT_HPP

# include <string>

# define DEFAULT_X
# define DEFAULT_Y
# define DEFAULT_Z

class Point {
protected:
	int	_x;
	int	_y;
	std::string	_z;

public:
	Point();
	Point( int x, int y, std::string z );
	Point( const Point &other );
	~Point();

	int getX( void ) const;
	void setX( const int x );
	int getY( void ) const;
	void setY( const int y );
	std::string getZ( void ) const;
	void setZ( const std::string z );

    Point &operator=( const Point &other );
};

#endif // POINT_HPP
