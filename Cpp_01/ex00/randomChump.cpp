#include "Zombie.hpp"

void	randomChump( const std::string name )
{
	Zombie zombie(name); // press F, if you feel sorry for him :(
	zombie.announce();
}
