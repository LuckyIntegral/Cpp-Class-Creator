
#pragma once

#ifndef F_HPP
# define F_HPP

# include <string>

class F {
public:
	F();
	F( const F &other );
	~F();

    F &operator=( const F &other );
};

#endif // F_HPP
