
#include <iostream>

#include "ShrubberyCreationForm.hpp"

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
	// to do later
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
	this->_target = other._target;
    return (*this);
}
