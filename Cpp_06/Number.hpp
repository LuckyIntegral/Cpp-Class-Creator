
#pragma once

#ifndef NUMBER_HPP
# define NUMBER_HPP

# include <string>

class Number {
protected:
	int	_floating_pint_number;

public:
    Number();
    Number( const Number &other );
    ~Number();

	int getFloating_pint_number( void ) const;
	void setFloating_pint_number( const int floating_pint_number );

    Number &operator=( const Number &other );
};

#endif // NUMBER_HPP

