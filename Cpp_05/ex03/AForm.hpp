
#pragma once

#ifndef A_FORM_HPP
# define A_FORM_HPP


# include <string>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

# define DEFAULT_NAME "Sertificate"
# define DEFAULT_GRADE 50
# define DEFAULT_MIN 150
# define DEFAULT_MAX 1

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
    AForm();
	AForm( const std::string name, const int gts, const int gte );
    AForm( const AForm &other );
    virtual	~AForm();

	void			validateGrades( const AForm &form,
		const int &gtsLimit, const int &gteLimit );
	void			validateExecution( const Bureaucrat &brc ) const;
	virtual void	beSigned( const Bureaucrat &brc );
	virtual void	execute( Bureaucrat const & executor ) const = 0;

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

	class FormIsNotSignedException : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

    virtual AForm    &operator=( const AForm &other );
};

std::ostream	&operator<<( std::ostream &out, const AForm &fm );


#endif // A_FORM_HPP
