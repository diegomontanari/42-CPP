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

// Niente catena di if: due array paralleli, i nomi dei livelli e i puntatori
// alle funzioni membro corrispondenti, nello stesso ordine. Trovo l'indice del
// livello e chiamo la funzione che sta allo stesso indice.
void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// void (Harl::*)(void): "puntatore a una funzione membro di Harl che non
	// riceve niente e restituisce void". &Harl::debug è l'indirizzo di debug.
	void	(Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			// Una funzione membro va chiamata su un oggetto: qui l'oggetto è
			// this, quindi (this->*functions[i])() chiama la funzione numero i.
			(this->*functions[i])();
			return ;
		}
	}
}
