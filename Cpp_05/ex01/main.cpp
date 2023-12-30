
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int	main( void ) {
	{
		std::cout << "\nTest case 1" << std::endl;
		try {
			Bureaucrat	a("John", 50);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 2" << std::endl;
		try {
			Bureaucrat	b("John", 160);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 3" << std::endl;
		try {
			Bureaucrat	c("John", -42);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 4" << std::endl;
		try {
			Bureaucrat	c("John", 1);
			std::cout << "Increment test invalid" << std::endl;
			c.incrementGrade();
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 5" << std::endl;
		try {
			Bureaucrat	c("John", 10);
			std::cout << "Increment test valid" << std::endl;
			c.incrementGrade();
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 6" << std::endl;
		try {
			Bureaucrat	c("John", 10);
			std::cout << "Decrement test valid" << std::endl;
			c.decrementGrade();
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 7" << std::endl;
		try {
			Bureaucrat	c("John", 150);
			std::cout << "Decrement test invalid" << std::endl;
			c.decrementGrade();
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}
	}
	std::cout << "\nLogs 2:" << std::endl;
	{
		std::cout << "\nTest case 1" << std::endl;
		try {
			Form	a("Form a", 40, 30);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 2" << std::endl;
		try {
			Form	b("Form b", 160, 30);
			std::cout << "OK" << std::endl;
		} catch ( Form::GradeTooHighException &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		} catch ( Form::GradeTooLowException &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 3" << std::endl;
		try {
			Form	b("Form a", -160, 30);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 4" << std::endl;
		try {
			Form	b("Form b", 60, -30);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 5" << std::endl;
		try {
			Form	b("Form b", 60, 230);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 6" << std::endl;
		try {
			Form	c("Form c", 60, 30);
			Bureaucrat	b("John", 80);

			std::cout << b << std::endl;
			std::cout << c << std::endl;

			b.signForm(c);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 7" << std::endl;
		try {
			Form	c("Form c", 60, 30);
			Bureaucrat	b("John", 20);

			std::cout << b << std::endl;
			std::cout << c << std::endl;

			b.signForm(c);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 8" << std::endl;
		try {
			Form	c("Form c", 60, 30);
			Bureaucrat	b("John", 20);

			std::cout << b << std::endl;
			std::cout << c << std::endl;

			c.beSigned(b);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}

		std::cout << "\nTest case 9" << std::endl;
		try {
			Form	c("Form c", 60, 30);
			Bureaucrat	b("John", 120);

			std::cout << b << std::endl;
			std::cout << c << std::endl;

			c.beSigned(b);
			std::cout << "OK" << std::endl;
		} catch ( std::exception &ex ) {
			std::cout << "KO " << ex.what() << std::endl;
		}
	}
	return (0);
}
