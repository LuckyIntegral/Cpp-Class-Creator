#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>

static bool isValidString(std::string input)
{
	if (input.length() == 0)
		return (false);
	for (int i = 0; i < (int) input.length(); i++)
		if (!(std::isprint(input[i]) || input[i] == ' '))
			return (false);
	return (true);
}

static void	ptint_invalid_input_message(void)
{
	std::cout << "Please make sure that you entered valid input" << std::endl;
	std::cout << "Valid input is a string that contains only chars that can be printed" << std::endl;
}

static void add(PhoneBook &database)
{
	Contact dto;
	std::string input;

	std::cout << "Please enter the contact first name: ";
	std::getline(std::cin, input);
	if (!isValidString(input))
		return ptint_invalid_input_message();
	dto.setFirstName(input);

	std::cout << "Please enter the contact last name: ";
	std::getline(std::cin, input);
	if (!isValidString(input))
		return ptint_invalid_input_message();
	dto.setLastName(input);

	std::cout << "Please enter the contact nickname: ";
	std::getline(std::cin, input);
	if (!isValidString(input))
			return ptint_invalid_input_message();
	dto.setNickname(input);

	std::cout << "Please enter the contact phone number: ";
	std::getline(std::cin, input);
	if (!isValidString(input))
		return ptint_invalid_input_message();
	dto.setPhoneNumber(input);

	std::cout << "Please enter the contact the darkest secret: ";
	std::getline(std::cin, input);
	if (!isValidString(input))
		return ptint_invalid_input_message();
	dto.setDarkestSecret(input);

	database.addContact(dto);
}

static void	truncate(std::string str)
{
	if (str.length() < 10)
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
	else
	{
		str.resize(9);
		std::cout << str << ".";
	}
}

static void	display_all_contacts(PhoneBook &database)
{
	Contact dto;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|  index   |first name| last name| nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 1; i <= database.getIndex() && i <= 8; i++)
	{
		dto = database.searchContact(i);
		std::cout << "|         " << i << "|";
		truncate(dto.getFirstName());
		std::cout << "|";
		truncate(dto.getLastName());
		std::cout << "|";
		truncate(dto.getNickname());
		std::cout << "|" << std::endl;
	}
}

static void search(PhoneBook &database)
{
	std::string input;
	Contact dto;
	std::cout << "Current state of database" << std::endl;
	display_all_contacts(database);

	std::cout << "Enter user index" << std::endl;
	std::getline(std::cin, input);
	if (input.length() > 1 || !std::isdigit(input[0]) || input[0] == '0'
		|| input[0] == '9' || input[0] - '0' > database.getIndex())
		std::cout << "Non valid user index '" << input << '\'' << std::endl;
	else
	{
		dto = database.searchContact(input[0] - '0');
		std::cout << "First name: '" << dto.getFirstName() << '\'' << std::endl;
		std::cout << "Last name: '" << dto.getLastName() << '\'' << std::endl;
		std::cout << "Nickname: '" << dto.getNickname() << '\'' << std::endl;
		std::cout << "Phone number: '" << dto.getPhoneNumber() << '\'' << std::endl;
	}
}

int	main(void)
{
	PhoneBook database;
	std::string input;

	while (true)
	{
		std::cout << "Please enter your command" << std::endl;
		std::cout << "These commands are available: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			add(database);
		else if (input == "SEARCH")
			search(database);
		else if (input == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << "Non valid command \"" << input << "\" was detected" << std::endl;
		if (std::cin.eof())
			break ;
		std::cout << std::endl;
	}
}
