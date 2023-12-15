
#include "HumanA.hpp"
#include "HumanB.hpp"

int main( void )
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{ // my extra test
		Weapon gun = Weapon("MP5");
		HumanB jack("Jack");
		jack.attack();
		jack.setWeapon(gun);
		jack.attack();
		gun.setType("M16A4");
		jack.attack();
	}
	return (0);
}