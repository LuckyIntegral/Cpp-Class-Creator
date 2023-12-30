
#pragma once

#ifndef FORM_HPP
# define FORM_HPP


# include <string>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

# define DEFAULT_NAME "Sertificate"
# define DEFAULT_GRADE 50

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
    Form();
	Form( const std::string name, const int gts, const int gte );
    Form( const Form &other );
    ~Form();

	void	beSigned( const Bureaucrat &brc );

	const std::string	getName( void ) const;
	bool				getStatus( void ) const;
	int					getGradeToSign( void ) const;
	int					getGradeToExecute( void ) const;

	class GradeTooHighException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

    Form    &operator=( const Form &other );
};

std::ostream	&operator<<( std::ostream &out, const Form &fm );


#endif // FORM_HPP
