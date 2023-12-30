
#include <iostream>

#include "Bureaucrat.hpp"

int	main( void ) {
	{
		std::cout << "\nTest case 1" << std::endl;
		try {
			Bureaucrat	a("John", 50);
			std::cout << "OK" << std::endl;
		} catch (...) {
			std::cout << "KO" << std::endl;
		}

		std::cout << "\nTest case 2" << std::endl;
		try {
			Bureaucrat	b("John", 160);
			std::cout << "OK" << std::endl;
		} catch ( Bureaucrat::GradeTooLowException &e ) {
			std::cout << "KO " << e.what() << std::endl;
		}

		std::cout << "\nTest case 3" << std::endl;
		try {
			Bureaucrat	c("John", -42);
			std::cout << "OK" << std::endl;
		} catch ( Bureaucrat::GradeTooHighException &e ) {
			std::cout << "KO " << e.what() << std::endl;
		}

		std::cout << "\nTest case 4" << std::endl;
		try {
			Bureaucrat	c("John", 1);
			std::cout << "Increment test invalid" << std::endl;
			c.incrementGrade();
			std::cout << "OK" << std::endl;
		} catch ( Bureaucrat::GradeTooHighException &e ) {
			std::cout << "KO " << e.what() << std::endl;
		}

		std::cout << "\nTest case 5" << std::endl;
		try {
			Bureaucrat	c("John", 10);
			std::cout << "Increment test valid" << std::endl;
			c.incrementGrade();
			std::cout << "OK" << std::endl;
		} catch ( Bureaucrat::GradeTooHighException &e ) {
			std::cout << "KO " << e.what() << std::endl;
		}

		std::cout << "\nTest case 6" << std::endl;
		try {
			Bureaucrat	c("John", 10);
			std::cout << "Decrement test valid" << std::endl;
			c.decrementGrade();
			std::cout << "OK" << std::endl;
		} catch ( Bureaucrat::GradeTooLowException &e ) {
			std::cout << "KO " << e.what() << std::endl;
		}

		std::cout << "\nTest case 7" << std::endl;
		try {
			Bureaucrat	c("John", 150);
			std::cout << "Decrement test invalid" << std::endl;
			c.decrementGrade();
			std::cout << "OK" << std::endl;
		} catch ( Bureaucrat::GradeTooLowException &e ) {
			std::cout << "KO " << e.what() << std::endl;
		}
	}
	return (0);
}
