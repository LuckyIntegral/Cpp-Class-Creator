
#include <iostream>

#include "AForm.hpp"

AForm::AForm()
		: _name(DEFAULT_NAME), _isSigned(false),
		 _gradeToSign(DEFAULT_GRADE), _gradeToExecute(DEFAULT_GRADE) {}

AForm::AForm( const std::string name, const int gts, const int gte )
		: _name(name), _isSigned(false),
		 _gradeToSign(gts), _gradeToExecute(gte) {
	this->validateGrades(*this, DEFAULT_MIN, DEFAULT_MIN);
}

AForm::AForm( const AForm &other )
		: _name(DEFAULT_NAME), _isSigned(false),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute) {
	this->validateGrades(*this, DEFAULT_MIN, DEFAULT_MIN);
}

AForm::~AForm() {}

void	AForm::validateGrades(const AForm &form,
		const int &gtsMin, const int &gteMin) {
	if (form._gradeToSign < DEFAULT_MAX || form._gradeToExecute < DEFAULT_MAX)
		throw AForm::GradeTooHighException();
	if (form._gradeToSign > gtsMin || form._gradeToExecute > gteMin)
		throw AForm::GradeTooLowException();
}

void	AForm::validateExecution( const Bureaucrat &brc ) const {
	if (this->_isSigned == false)
		throw FormIsNotSignedException();
	if (brc.getGrade() < DEFAULT_MAX)
		throw GradeTooHighException();
	if (brc.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
}

void	AForm::beSigned( const Bureaucrat &brc ) {
	if (brc.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const std::string	AForm::getName( void ) const {
	return (this->_name);
}

bool	AForm::getStatus( void ) const {
	return (this->_isSigned);
}

int	AForm::getGradeToSign( void ) const {
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute( void ) const {
	return (this->_gradeToExecute);
}

const char	*AForm::GradeTooHighException::what( void ) const throw() {
	return ("grade too high");
}

const char	*AForm::GradeTooLowException::what( void ) const throw() {
	return ("grade too low");
}

const char	*AForm::FormIsNotSignedException::what( void ) const throw() {
	return ("form is not signed");
}

AForm &AForm::operator=( const AForm &other ) {
	this->_isSigned = other._isSigned;
    return (*this);
}

std::ostream	&operator<<( std::ostream &out, const AForm &fm ) {
	out << fm.getName() << " form, status "
		<< (fm.getStatus() ? "signed " : "not signed")
		<< ", grade to sign " << fm.getGradeToSign()
		<< ", grade to execute " << fm.getGradeToExecute();
	return (out);
}
