
#include "Harl.hpp"
#include <iostream>

Harl::Harl( void ) {}
Harl::~Harl( ) {}

void	Harl::complain( std::string level )
{
	const std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	Harl	harl;
	size_t	i;

	for (i = 0; i < sizeof (levels) / sizeof (std::string); i++)
		if (levels[i] == level)
			break ;

	switch (i)
	{
		case (0):
			harl.debug();
		case (1):
			harl.info();
		case (2):
			harl.warning();
		case (3):
			harl.error();
			break ;
		default :
			std::cout << "No text for [" << level << "] level" << std::endl;
			std::cout << "list of levels: DEBUG INFO WARNING ERROR" << std::endl;
	}
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "The text for debug level" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "The text for warning level" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "The text for info level" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "The text for error level" << std::endl;
}
