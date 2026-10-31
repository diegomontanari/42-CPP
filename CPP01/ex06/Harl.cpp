#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Stampa tutti i messaggi dal livello scelto in su, usando lo switch con il
// "fall-through": un case senza break continua nel case successivo.
void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			index = -1;

	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			index = i;

	switch (index)
	{
		case 0:
			debug();
			std::cout << std::endl;
			// niente break: si prosegue con INFO
			// fall through
		case 1:
			info();
			std::cout << std::endl;
			// niente break: si prosegue con WARNING
			// fall through
		case 2:
			warning();
			std::cout << std::endl;
			// niente break: si prosegue con ERROR
			// fall through
		case 3:
			error();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
