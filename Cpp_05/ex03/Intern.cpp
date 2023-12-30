
#include <iostream>

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern( const Intern &other ) {
	(void) other;
}

Intern::~Intern() {}

AForm	*Intern::makeForm( std::string &form, std::string &target ) const {
	const std::string	levels[3] = {
		"robotomy",
		"president",
		"shrubbery",
	};
	int	index = 0;
	while (index < 3 && levels[index] != form)
		index++;
	switch (index) {
		case (0):
			std::cout << "Intern creates robotomy form" << std::endl;
			return (new RobotomyRequestForm(target));
		case (1):
			std::cout << "Intern creates president form" << std::endl;
			return (new PresidentialPardonForm(target));
		case (2):
			std::cout << "Intern creates shrubbery form" << std::endl;
			return (new ShrubberyCreationForm(target));
	}
	std::cout << "Intern couldn't create a form" << std::endl;
	return (NULL);
}


Intern &Intern::operator=( const Intern &other ) {
	(void) other;
    return (*this);
}
