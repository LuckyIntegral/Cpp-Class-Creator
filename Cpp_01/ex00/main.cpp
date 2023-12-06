
#include "Zombie.h"

int	main( void )
{
	// heap zombie that will die at the end of the scope after using keyword 'delete'
	Zombie	*heapOne = newZombie("Charlie from main");
	heapOne->announce();

	// stack one, lives on the stack, will die automatically at the end of scope
	Zombie	stackOne("Rick from main");
	stackOne.announce();

	// for visualization
	std::cout << "\nFunction randomChump calls\n" << std::endl;
	randomChump("Kevin from function scope");

	// for visualization
	std::cout << "\nRight now '" << heapOne->getName()
		<< "' and '" << stackOne.getName() << "' are alive\n" << std::endl;

	// intendent level scope, almost the same as function scope for the stack zombie
	{
		Zombie	mainScopeZombie;
		mainScopeZombie.announce();
	} // must die at the end of this scope

	// for visualization only
	std::cout << "\nRight now again only '" << heapOne->getName()
		<< "' and '" << stackOne.getName() << "' are alive\n" << std::endl;

	// prooves
	heapOne->announce();
	stackOne.announce();

	// first dies heap zombie Charlie
	delete heapOne;

	// for visualization only
	std::cout << "\nRight now only '" << stackOne.getName() << "' is alive\n" << std::endl;
	stackOne.getName();

	// Rick dies automatically at the end of the scope
	return (0);
}
