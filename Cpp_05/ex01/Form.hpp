
#ifndef FORM_HPP
# define FORM_HPP


# include <string>

class Form {
public:
    Form();
    Form( const Form &other );
    ~Form();

    Form    &operator=( const Form &other );
};


#endif // FORM_HPP

