
#pragma once

#include <string>

class Zombie
{
public:
	Zombie( void );
	Zombie( std::string );
	~Zombie( void );

	void	announce( void ) const;

	std::string	getName( void ) const;
	void		setName( std::string );

private:
	std::string	_name;
};
