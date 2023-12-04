
#pragma once

#include <string>

class Zombie
{
public:
	Zombie( void );
	Zombie( std::string );
	~Zombie( void );

	void	announce( void );

private:
	std::string	_name;
};
