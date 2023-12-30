
#include <iostream>

#include "ScalarConverter.hpp"

int main( int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: ./scalar <literal>" << std::endl;
	} else {
		std::string	convert(argv[1]);
		ScalarConverter::convert(convert);
	}
	return (0);
}
