#include "PhoneBook.hpp"
#include <iostream>	// std::cout, std::cin, std::getline
#include <iomanip>	// std::setw, std::right
#include <cstdlib>	// std::exit

// Initialization list: i membri vengono inizializzati prima del corpo del costruttore
PhoneBook::PhoneBook() : _count(0), _next(0)
{
}

PhoneBook::~PhoneBook()
{
}

// Legge una riga non vuota. Se l'utente preme Ctrl+D (EOF) restituisce false.
bool	PhoneBook::_readField(const std::string &prompt, std::string &out)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return (false);
		// Un campo fatto solo di spazi conta come vuoto
		if (out.find_first_not_of(" \t") != std::string::npos)
			return (true);
		std::cout << "This field can't be empty." << std::endl;
	}
}

void	PhoneBook::add()
{
	std::string	fields[5];
	const char	*prompts[5] = {
		"First name: ",
		"Last name: ",
		"Nickname: ",
		"Phone number: ",
		"Darkest secret: "
	};

	for (int i = 0; i < 5; i++)
	{
		if (!_readField(prompts[i], fields[i]))
		{
			std::cout << std::endl;
			std::exit(0);
		}
	}
	_contacts[_next].setFields(fields[0], fields[1], fields[2], fields[3], fields[4]);
	// Buffer circolare: dopo l'indice 7 si torna a 0, sovrascrivendo il più vecchio
	_next = (_next + 1) % MAX_CONTACTS;
	if (_count < MAX_CONTACTS)
		_count++;
	std::cout << "Contact saved." << std::endl;
}

// Tronca a 10 caratteri: se il testo è più lungo, i primi 9 più un punto
std::string	PhoneBook::_formatColumn(const std::string &text)
{
	if (text.length() > 10)
		return (text.substr(0, 9) + ".");
	return (text);
}

void	PhoneBook::_printTable() const
{
	std::cout << std::right
		<< std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		// setw vale solo per il valore stampato subito dopo: va ripetuto ogni volta
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << _formatColumn(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << _formatColumn(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << _formatColumn(_contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::_printContact(int index) const
{
	const Contact	&c = _contacts[index];

	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

void	PhoneBook::search() const
{
	std::string	input;

	if (_count == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return ;
	}
	_printTable();
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		std::exit(0);
	}
	// Accettiamo solo una singola cifra compresa tra 0 e _count - 1
	if (input.length() != 1 || input[0] < '0' || input[0] - '0' >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	_printContact(input[0] - '0');
}
