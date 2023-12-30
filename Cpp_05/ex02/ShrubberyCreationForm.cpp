
#include <exception>
#include <fstream>
#include <iostream>

#include "ShrubberyCreationForm.hpp"

const std::string TREE = "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\";

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(SHRB_NAME, SHRB_GTS_REQ, SHRB_GTE_REQ),
	_target(SHRB_DEF_TARGET) {}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target )
	: AForm(SHRB_NAME, SHRB_GTS_REQ, SHRB_GTE_REQ),
	_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other )
	: AForm(SHRB_NAME, SHRB_GTS_REQ, SHRB_GTE_REQ),
	_target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	this->validateExecution(executor);
	std::ofstream	file((this->_target + "_shrubbery").c_str(), std::ios_base::app);

	if (!file.is_open())
		throw ShrubberyCreationForm::CannotOpenFile();
	file << '\n' << TREE << '\n' << std::endl;
	file.close();
}

const char	*ShrubberyCreationForm::CannotOpenFile::what() const throw() {
	return ("cannot open file");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
	this->_target = other._target;
    return (*this);
}
