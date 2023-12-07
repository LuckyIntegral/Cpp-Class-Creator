
#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name );

int	main( void )
{
	const int	N = 10;
	Zombie		*zombies = zombieHorde(N, "Morty from Mars");

	// for visual v1
	for (int i = 0; i < N; i++) {
		std::cout << "Zombie number '" << i << "' with name '"
			<< zombies->getName() << "'"<< std::endl;
	}

	// for visual v2
	std::cout << std::endl;
	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}

	// for visual v3
	std::cout << std::endl;
	delete[] zombies;

	// for visual v4
	std::cout << std::endl;
	std::cout << "All the zombies are died by this time" << std::endl;

	return (0);
}
