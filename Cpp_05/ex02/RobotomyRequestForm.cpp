
#include <iostream>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(RBTM_NAME, RBTM_GTS_REQ, RBTM_GTE_REQ),
	_target(RBTM_DEF_TARGET) {}

RobotomyRequestForm::RobotomyRequestForm( const std::string target)
	: AForm(RBTM_NAME, RBTM_GTS_REQ, RBTM_GTE_REQ),
	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other )
	: AForm(RBTM_NAME, RBTM_GTS_REQ, RBTM_GTE_REQ),
	_target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	this->validateExecution(executor);
	// to do later
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
    this->_target = other._target;
    return (*this);
}
