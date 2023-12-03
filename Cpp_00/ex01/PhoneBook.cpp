#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_index = 0;
}

void PhoneBook::addContact(Contact contact)
{
	m_contacts[m_index++ % 8] = contact;
}

Contact PhoneBook::searchContact(int index)
{
	return (m_contacts[index - 1]);
}

int PhoneBook::getIndex() const
{
	return (m_index);
}
