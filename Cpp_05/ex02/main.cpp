
#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void ) {
	{
		std::cout << "\nTest case 1" << std::endl;
		try {
			Bureaucrat	c("John", 150);
			AForm	*shrb = new ShrubberyCreationForm("Forest");

			std::cout << "Invalid execution of shrubbery form" << std::endl;

			c.executeForm(*shrb);
			c.signForm(*shrb);

			std::cout << "OK" << std::endl;
			delete shrb;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 2" << std::endl;
		try {
			Bureaucrat	c("John", 140);
			AForm	*shrb = new ShrubberyCreationForm("Forest");

			std::cout << "Valid execution of shrubbery form" << std::endl;

			c.executeForm(*shrb);
			c.signForm(*shrb);
			c.executeForm(*shrb);

			std::cout << "OK" << std::endl;
			delete shrb;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 3" << std::endl;
		try {
			Bureaucrat	c("John", 120);
			AForm	*shrb = new ShrubberyCreationForm("Forest");

			std::cout << "Valid execution of shrubbery form" << std::endl;

			c.executeForm(*shrb);
			c.signForm(*shrb);
			c.executeForm(*shrb);

			std::cout << "OK" << std::endl;
			delete shrb;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 4" << std::endl;
		try {
			Bureaucrat	c("John", 140);
			AForm	*tmp = new RobotomyRequestForm("Manufactory");

			std::cout << "Valid execution of shrubbery form" << std::endl;

			c.executeForm(*tmp);
			c.signForm(*tmp);
			c.executeForm(*tmp);

			std::cout << "OK" << std::endl;
			delete tmp;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 5" << std::endl;
		try {
			Bureaucrat	c("John", 50);
			AForm	*tmp = new RobotomyRequestForm("Manufactory");

			std::cout << "Valid execution of shrubbery form" << std::endl;

			c.executeForm(*tmp);
			c.signForm(*tmp);
			c.executeForm(*tmp);

			std::cout << "OK" << std::endl;
			delete tmp;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 6" << std::endl;
		try {
			Bureaucrat	c("John", 30);
			AForm	*tmp = new RobotomyRequestForm("Manufactory");

			std::cout << "Valid execution of shrubbery form" << std::endl;

			c.executeForm(*tmp);
			c.signForm(*tmp);
			c.executeForm(*tmp);

			std::cout << "OK" << std::endl;
			delete tmp;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 7" << std::endl;
		try {
			Bureaucrat	c("John", 30);
			AForm	*tmp = new PresidentialPardonForm("Office");

			std::cout << "Valid execution of shrubbery form" << std::endl;

			c.executeForm(*tmp);
			c.signForm(*tmp);
			c.executeForm(*tmp);

			std::cout << "OK" << std::endl;
			delete tmp;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 8" << std::endl;
		try {
			Bureaucrat	c("John", 20);
			AForm	*tmp = new PresidentialPardonForm("Office");

			std::cout << "Valid execution of shrubbery form" << std::endl;

			c.executeForm(*tmp);
			c.signForm(*tmp);
			c.executeForm(*tmp);

			std::cout << "OK" << std::endl;
			delete tmp;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 9" << std::endl;
		try {
			Bureaucrat	c("John", 3);
			AForm	*tmp = new PresidentialPardonForm("Office");

			std::cout << "Valid execution of shrubbery form" << std::endl;

			c.executeForm(*tmp);
			c.signForm(*tmp);
			c.executeForm(*tmp);

			std::cout << "OK" << std::endl;
			delete tmp;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}
	}
	return (0);
}
