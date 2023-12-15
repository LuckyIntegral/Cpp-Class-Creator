
#pragma once

#include "Weapon.hpp"

#define DEFAULT_NAME "Nick"
#define DEFAULT_WEAPON "fists"

class HumanB
{
private:
	Weapon		*_weapon;
	std::string	_name;

public:
	HumanB( std::string name );
	~HumanB();

	void		attack( void ) const;

	Weapon		getWeapon( void ) const;
	std::string	getName( void ) const;
	void		setWeapon( Weapon &weapon );
	void		setName( const std::string &type );
};