
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickname;
		std::string m_phoneNumber;
		std::string m_darkestSecret;

	public:
		Contact();
		Contact(std::string firstName,
			std::string lastName,
			std::string nickname,
			std::string phoneNumber,
			std::string darkestSecret);
		~Contact();

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

		void		setFirstName(std::string value);
		void		setLastName(std::string value);
		void		setNickname(std::string value);
		void		setPhoneNumber(std::string value);
		void		setDarkestSecret(std::string value);
};

#endif
