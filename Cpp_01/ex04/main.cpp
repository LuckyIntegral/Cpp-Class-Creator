
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>

std::string	replace(std::string line, std::string s1, std::string s2)
{
	std::string	result = "";

	std::size_t	begin = 0;
	std::size_t	end = 0;
	if (s1 == "")
		return (line);
	while (end != std::string::npos)
	{
		std::size_t	end = line.find(s1, begin);
		if (end == std::string::npos)
		{
			result += line.substr(begin, end);
			break ;
		}
		result += line.substr(begin, end - begin);
		begin = end + s1.length();
		result += s2;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	// open a file for reading
	std::ifstream	inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cout << "cannot open file <" << argv[1] << ">" << std::endl;
		return (1);
	}

	// create and open a file for writing
	std::string		outFileName;
	outFileName = argv[1];
	outFileName += ".replace";

	std::ofstream	outFile(outFileName.c_str());

	if (!outFile.is_open())
	{
		std::cout << "Cannot create a file with name '" << argv[1]
			<< ".replace'" << std::endl;
		inFile.close();
		return (1);
	}

	std::string	line = "";
	std::string	result = "";

	while (std::getline(inFile, line))
	{
		result += line;
		if (inFile.eof())
			break ;
		result += '\n';
	}

	outFile << replace(result, argv[2], argv[3]);

	// no leaks:)
	inFile.close();
	outFile.close();

	return (0);
}