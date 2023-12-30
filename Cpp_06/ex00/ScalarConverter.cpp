
#include <iostream>

#include "ScalarConverter.hpp"

void	ScalarConverter::convert( std::string &original ) {
	std::cout << original << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter( const ScalarConverter &other ) {
	(void) other;
}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ) {
	(void) other;
	return (*this);
}
