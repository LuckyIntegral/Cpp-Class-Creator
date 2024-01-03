
#pragma once

#ifndef F_HPP
# define F_HPP


# include <string>

# define DEFAULT_G

class f {
protected:
	int	_g;

public:
	f();
	f( int g );
	f( const f &other );
	~f();

	int getG( void ) const;
	void setG( const int g );

    f &operator=( const f &other );
};

std::ostream	&operator<<( std::ostream &stream, const f &instance );


#endif // F_HPP
