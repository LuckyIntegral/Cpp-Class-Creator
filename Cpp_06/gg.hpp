#pragma once

#ifndef GG_HPP
# define GG_HPP

# include <string>

# define DEFAULT_NUMBER
# define DEFAULT_NUMBERS

class gg {
protected:
	int	_number;
	int	_numbers;

public:
	gg();
	gg( int number, int numbers );
	gg( const gg &other );
	~gg();

	int getNumber( void ) const;
	void setNumber( const int number );
	int getNumbers( void ) const;
	void setNumbers( const int numbers );

    gg &operator=( const gg &other );
};

#endif // GG_HPP

