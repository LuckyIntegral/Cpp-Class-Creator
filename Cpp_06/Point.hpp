
#pragma once

#ifndef POINT_HPP
# define POINT_HPP

# include <string>

# define DEFAULT_X
# define DEFAULT_Y
# define DEFAULT_Z

class Point {
protected:
	float	_x;
	float	_y;
	float	_z;

public:
	Point();
	Point( float x, float y, float z );
	Point( const Point &other );
	~Point();

	float getX( void ) const;
	void setX( const float x );
	float getY( void ) const;
	void setY( const float y );
	float getZ( void ) const;
	void setZ( const float z );

    Point &operator=( const Point &other );
};

#endif // POINT_HPP
