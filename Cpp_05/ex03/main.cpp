
#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main( int argc, const char **argv ) {
	if (argc != 3) {
		std::cout << "Usage: ./intern <form_type> <form_target>\n"
			"Available forms: robotomy, president, shrubbery" << std::endl;
	} else {
		Bureaucrat	manager("Manager", 1); // the highest possible grade
		std::string str1(argv[1]);
		std::string str2(argv[2]);
		Intern 		intern;

    	AForm		*rrf = intern.makeForm(str1, str2);

		if (rrf != NULL) {
			manager.signForm(*rrf);
			manager.executeForm(*rrf);
			delete (rrf);
		}
	}
	return (0);
}
