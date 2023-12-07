#pragma once

#include <string>

#define DEFAULT_TYPE "Default type"

class Weapon
{
private:
	std::string	_type;

public:
	Weapon( void );
	Weapon( const std::string );
	~Weapon();

	const std::string	&getType( void ) const;
	void				setType( const std::string type );
};
