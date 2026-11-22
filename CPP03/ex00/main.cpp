#include "ClapTrap.hpp"
#include <iostream>

static void	title(const std::string &text)
{
	std::cout << std::endl << "=== " << text << " ===" << std::endl;
}

int	main(void)
{
	title("1. Nascita (default e con nome)");
	ClapTrap	nobody;
	ClapTrap	diego("Diego");

	title("2. Attacco normale: l'energia scende di 1");
	diego.attack("Target");

	title("3. Danno parziale, poi danno che supera la vita");
	diego.takeDamage(4);
	diego.takeDamage(1000);

	title("4. Riparazione di un robot vivo");
	ClapTrap	sara("Sara");
	sara.takeDamage(3);
	sara.beRepaired(2);

	title("5. Robot a 0 vita: non puo' attaccare ne' ripararsi");
	diego.attack("Target");
	diego.beRepaired(5);
	diego.takeDamage(1);

	title("6. Energia finita: 10 azioni, poi l'undicesima non fa niente");
	ClapTrap	tired("Tired");
	for (int i = 0; i < 10; i++)
		tired.attack("Wall");
	tired.attack("Wall");
	tired.beRepaired(1);

	title("7. Copia e assegnazione");
	ClapTrap	original("Original");
	original.attack("Someone");
	original.takeDamage(3);
	ClapTrap	copy(original);
	ClapTrap	assigned("Assigned");
	assigned = original;
	original.takeDamage(2);
	copy.beRepaired(1);
	ClapTrap	&same = assigned;
	assigned = same;		// auto-assegnazione, passando da un riferimento

	title("Fine: i distruttori partono in ordine inverso");
	return (0);
}
