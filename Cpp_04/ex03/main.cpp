
#include <iostream>

#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main( void ) {
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << "\nLogs 2\n" << std::endl;
	{
		IMateriaSource	*src = new MateriaSource();
		for (int i = 0; i < 4; ++i)
			src->learnMateria(new Ice());

		ICharacter	*me = new Character("me");
		std::cout << "tmp = " << src->createMateria("random") << std::endl;

		for (int i = 0; i < 4; ++i)
			me->equip(src->createMateria("ice"));

		ICharacter	*bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(42, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		MateriaSource ms;
		ms.learnMateria(new Cure());
		ms.learnMateria(new Cure());
		{
			MateriaSource msi;
			msi = ms;
		}
	}
	{
		Character ms;
		ms.equip(new Cure());
		ms.equip(new Cure());
		{
			Character msi;
			msi = ms;
		}
	}
	return (0);
}
