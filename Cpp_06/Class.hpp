
#pragma once

#ifndef CLASS_HPP
# define CLASS_HPP


# include <string>

class Class {
public:
	Class();
	Class( const Class &other );
	~Class();

    Class &operator=( const Class &other );
};

std::ostream	&operator<<( std::ostream &stream, const Class &instance );


#endif // CLASS_HPP
