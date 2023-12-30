
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


# include <string>

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat( const Bureaucrat &other );
    ~Bureaucrat();

    Bureaucrat    &operator=( const Bureaucrat &other );
};


#endif // BUREAUCRAT_HPP

