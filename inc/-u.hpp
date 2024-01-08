
#pragma once

#ifndef -U_HPP
# define -U_HPP


# include <string>

class -u {
public:
	-u();
	-u( const -u &other );
	~-u();

	-u &operator=( const -u &other );
};

std::ostream	&operator<<( std::ostream &stream, const -u &instance );


#endif // -U_HPP
