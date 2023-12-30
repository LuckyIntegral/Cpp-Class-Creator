
#include <iostream>

#include "Form.hpp"

static void	validateGrade( const int &grade ) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form()
		: _name(DEFAULT_NAME), _isSigned(false),
		 _gradeToSign(DEFAULT_GRADE), _gradeToExecute(DEFAULT_GRADE) {}

Form::Form( const std::string name, const int gts, const int gte )
		: _name(name), _isSigned(false),
		 _gradeToSign(gts), _gradeToExecute(gte) {
	validateGrade(this->_gradeToExecute);
	validateGrade(this->_gradeToSign);
}

Form::Form( const Form &other )
		: _name(DEFAULT_NAME), _isSigned(false),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute) {
	validateGrade(this->_gradeToExecute);
	validateGrade(this->_gradeToSign);
}

Form::~Form() {}

void	Form::beSigned( const Bureaucrat &brc ) {
	if (brc.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const std::string	Form::getName( void ) const {
	return (this->_name);
}

bool	Form::getStatus( void ) const {
	return (this->_isSigned);
}

int	Form::getGradeToSign( void ) const {
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute( void ) const {
	return (this->_gradeToExecute);
}

const char	*Form::GradeTooHighException::what( void ) const throw() {
	return ("grade too high");
}

const char	*Form::GradeTooLowException::what( void ) const throw() {
	return ("grade too low");
}

Form &Form::operator=( const Form &other ) {
	this->_isSigned = other._isSigned;
    return (*this);
}

std::ostream	&operator<<( std::ostream &out, const Form &fm ) {
	out << fm.getName() << " form, status "
		<< (fm.getStatus() ? "signed " : "not signed")
		<< ", grade to sign " << fm.getGradeToSign()
		<< ", grade to execute " << fm.getGradeToExecute();
	return (out);
}
