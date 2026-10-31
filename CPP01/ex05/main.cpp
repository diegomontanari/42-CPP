#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	std::cout << "-- livello sconosciuto (non stampa niente):" << std::endl;
	harl.complain("PIZZA");
	return (0);
}
