
#pragma once

#ifndef A_HPP
# define A_HPP

# include <string>

class A {
public:
	A();
	A( const A &other );
	~A();

    A &operator=( const A &other );
};

#endif // A_HPP
