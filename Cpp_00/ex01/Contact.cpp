#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	m_firstName = firstName;
	m_lastName = lastName;
	m_nickname = nickname;
	m_phoneNumber = phoneNumber;
	m_darkestSecret = darkestSecret;
}

Contact::~Contact() {}

std::string Contact::getFirstName() const
{
	return (m_firstName);
}

std::string Contact::getLastName() const
{
	return (m_lastName);
}

std::string Contact::getNickname() const
{
	return (m_nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (m_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (m_darkestSecret);
}

void Contact::setFirstName(std::string value)
{
	m_firstName = value;
}

void Contact::setLastName(std::string value)
{
	m_lastName = value;
}

void Contact::setNickname(std::string value)
{
	m_nickname = value;
}

void Contact::setPhoneNumber(std::string value)
{
	m_phoneNumber = value;
}

void Contact::setDarkestSecret(std::string value)
{
	m_darkestSecret = value;
}
