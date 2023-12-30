
#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(PRES_NAME, PRES_GTS_REQ, PRES_GTE_REQ),
	_target(PRES_DEF_TARGET) {}

PresidentialPardonForm::PresidentialPardonForm( const std::string target )
	: AForm(PRES_NAME, PRES_GTS_REQ, PRES_GTE_REQ),
	_target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other )
	: AForm(PRES_NAME, PRES_GTS_REQ, PRES_GTE_REQ),
	_target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	this->validateExecution(executor);
	std::cout << this->_target
		<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
	this->_target = other._target;
    return (*this);
}
