#include "Contact.hpp"

// Le std::string si inizializzano da sole a stringa vuota:
// il costruttore non deve fare nulla.
Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFields(const std::string &firstName,
			const std::string &lastName,
			const std::string &nickname,
			const std::string &phoneNumber,
			const std::string &darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

const std::string	&Contact::getFirstName() const
{
	return (_firstName);
}

const std::string	&Contact::getLastName() const
{
	return (_lastName);
}

const std::string	&Contact::getNickname() const
{
	return (_nickname);
}

const std::string	&Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

const std::string	&Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}
