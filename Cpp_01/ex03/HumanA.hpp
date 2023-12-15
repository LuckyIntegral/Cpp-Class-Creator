
#pragma once

#include "Weapon.hpp"

#define DEFAULT_NAME "Nick"

class HumanA
{
private:
	Weapon		&_weapon;
	std::string	_name;

public:
	HumanA( std::string name, Weapon &weapon );
	~HumanA();

	void		attack( void ) const;

	Weapon		getWeapon( void ) const;
	std::string	getName( void ) const;
	void		setWeapon( Weapon &weapon );
	void		setName( const std::string &type );
};
