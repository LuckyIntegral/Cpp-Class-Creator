
#pragma once

#ifndef F_HPP
# define F_HPP

# include <string>

class f {
public:
	f();
	f( const f &other );
	~f();

    f &operator=( const f &other );
};

#endif // F_HPP
