
#include <iostream>
#include <locale>

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
	std::cout << "*drilling noises*" << std::endl;
	std::cout << "*drilling noises*" << std::endl;
	std::cout << "*drilling noises*" << std::endl;
	if (std::time(NULL) % 2)
		throw RobotomyFailure();
	std::cout << this->_target
		<< " has been robotomized successfully" << std::endl;
}

const char	*RobotomyRequestForm::RobotomyFailure::what() const throw() {
	return ("robotomy cannot be robotomized successfully");
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
    this->_target = other._target;
    return (*this);
}
