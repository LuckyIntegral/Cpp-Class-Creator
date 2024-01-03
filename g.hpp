
#pragma once

#ifndef G_HPP
# define G_HPP


# include <string>

class g {
public:
	g();
	g( const g &other );
	~g();

    g &operator=( const g &other );
};

std::ostream	&operator<<( std::ostream &stream, const g &instance );


#endif // G_HPP
