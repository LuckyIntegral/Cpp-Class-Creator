
#pragma once

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP


# include <string>

# include "AForm.hpp"

# define PRES_DEF_TARGET "Offices"
# define PRES_NAME "Pardon-form"
# define PRES_GTS_REQ 25
# define PRES_GTE_REQ 5

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm( const std::string target );
    PresidentialPardonForm( const PresidentialPardonForm &other );
    ~PresidentialPardonForm();
	
	void	execute( Bureaucrat const & executor ) const;

    PresidentialPardonForm    &operator=( const PresidentialPardonForm &other );
};


#endif // PRESIDENTIAL_PARDON_FORM_HPP
