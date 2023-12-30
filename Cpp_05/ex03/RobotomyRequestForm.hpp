
#pragma once

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP


# include <string>

# include "AForm.hpp"

# define RBTM_DEF_TARGET "Iron manufacture"
# define RBTM_NAME "Robotototomy"
# define RBTM_GTS_REQ 72
# define RBTM_GTE_REQ 45

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm( const std::string target );
    RobotomyRequestForm( const RobotomyRequestForm &other );
    ~RobotomyRequestForm();

	void	execute( Bureaucrat const & executor ) const;

	class RobotomyFailure : public std::exception {
	public:
		const char	*what( void ) const throw();
	};

    RobotomyRequestForm    &operator=( const RobotomyRequestForm &other );
};


#endif // ROBOTOMY_REQUEST_FORM_HPP
