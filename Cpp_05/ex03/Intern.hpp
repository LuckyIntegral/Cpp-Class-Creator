
#ifndef INTERN_HPP
# define INTERN_HPP


# include <string>

# include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern( const Intern &other );
    ~Intern();

	AForm	*makeForm( std::string &form, std::string &target ) const;

    Intern    &operator=( const Intern &other );
};


#endif // INTERN_HPP
