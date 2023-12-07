
#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*crowd = new Zombie[N]();

	for (int i = 0; i < N; i++)
		crowd[i].setName(name);

	return (crowd);
}