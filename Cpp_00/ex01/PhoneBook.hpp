#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact m_contacts[8];
		int m_index;

	public:
		PhoneBook();
		void addContact(Contact contact);
		Contact searchContact(int index);
		int getIndex() const;
};

#endif
