
#pragma once

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP


# include <string>

# include "AForm.hpp"

# define SHRB_DEF_TARGET "Wooden enterprice"
# define SHRB_NAME "Shrrruberrry"
# define SHRB_GTS_REQ 145
# define SHRB_GTE_REQ 137

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm( const std::string target );
    ShrubberyCreationForm( const ShrubberyCreationForm &other );
    ~ShrubberyCreationForm();

	void	execute( Bureaucrat const & executor ) const;

	class CannotOpenFile : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

    ShrubberyCreationForm    &operator=( const ShrubberyCreationForm &other );
};


#endif // SHRUBBERY_CREATION_FORM_HPP
