#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;	// istanza della classe: niente new, vive sullo stack
	std::string	command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		// getline legge l'intera riga; se fallisce siamo a EOF (Ctrl+D)
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			break ;
		}
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			break ;
		// Qualsiasi altro input viene ignorato
	}
	return (0);
}
