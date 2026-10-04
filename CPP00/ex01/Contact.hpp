#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

// Un singolo contatto della rubrica.
// I dati sono private: dall'esterno si leggono solo tramite i getter
// e si scrivono solo tramite setFields(). Questo è l'incapsulamento.
class Contact
{
	public:
		Contact();
		~Contact();

		void				setFields(const std::string &firstName,
								const std::string &lastName,
								const std::string &nickname,
								const std::string &phoneNumber,
								const std::string &darkestSecret);

		// "const" dopo le parentesi: la funzione promette di non modificare l'oggetto
		const std::string	&getFirstName() const;
		const std::string	&getLastName() const;
		const std::string	&getNickname() const;
		const std::string	&getPhoneNumber() const;
		const std::string	&getDarkestSecret() const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
