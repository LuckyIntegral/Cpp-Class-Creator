
#include "Zombie.h"

int	main( void )
{
	// heap zombie that will die at the end of the scope after using keyword 'delete'
	Zombie	*heapOne = newZombie( "Charlie from main" );
	heapOne->announce();

	// stack one, lives on the stack, will die automatically at the end of scope
	Zombie	stackOne( "Rick from main" );
	stackOne.announce();

	// lol, the function creates a zombie, that dies instantly within the function
	randomChump( "Kevin from function scope" );

	// for visualization
	std::cout << "\nRight now Charlie and Rick are alive\n" << std::endl;

	// for test purpose only
	{
		Zombie	mainScopeZombie;
		mainScopeZombie.announce();
	} // must die at the end of its scope

	// for visualization only
	std::cout << "\nRight now again only Charlie and Rick are alive\n" << std::endl;

	// first dies heap zombie Charlie
	delete heapOne;

	// Rick dies automatically at the end of the scope
	return (0);
}
