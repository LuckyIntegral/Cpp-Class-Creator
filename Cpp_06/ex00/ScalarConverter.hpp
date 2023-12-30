
#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP


# include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter( const ScalarConverter &other );
    ~ScalarConverter();

    ScalarConverter    &operator=( const ScalarConverter &other );
public:
	static void	convert( std::string &original );
};


#endif // SCALAR_CONVERTER_HPP
