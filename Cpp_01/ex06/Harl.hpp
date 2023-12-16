
#pragma once

#include <string>

class Harl
{
public:
	Harl( void );
	~Harl( );

	void	complain( std::string level );

private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};
