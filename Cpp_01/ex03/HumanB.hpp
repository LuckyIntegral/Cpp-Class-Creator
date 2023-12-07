
#pragma once

#include "Weapon.hpp"

#define DEFAULT_NAME "Nick"

class HumanB
{
private:
	Weapon		*_weapon;
	std::string	_name;

public:
	HumanB( std::string &name, Weapon *weapon );
	~HumanB();

	void		attack( void ) const;

	Weapon		getWeapon( void ) const;
	std::string	getName( void ) const;
	void		setWeapon( const Weapon weapon );
	void		setName( const std::string type );
};