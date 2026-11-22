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
	ClapTrap	bolt("R2-D2");

	title("2. Attacco normale: l'energia scende di 1");
	bolt.attack("Skynet");

	title("3. Danno parziale, poi danno che supera la vita");
	bolt.takeDamage(4);
	bolt.takeDamage(1000);

	title("4. Riparazione di un robot vivo");
	ClapTrap	nova("WALL-E");
	nova.takeDamage(3);
	nova.beRepaired(2);

	title("5. Robot a 0 vita: non puo' attaccare ne' ripararsi");
	bolt.attack("Skynet");
	bolt.beRepaired(5);
	bolt.takeDamage(1);

	title("6. Energia finita: 10 azioni, poi l'undicesima non fa niente");
	ClapTrap	tired("Marvin");
	for (int i = 0; i < 10; i++)
		tired.attack("Skynet");
	tired.attack("Skynet");
	tired.beRepaired(1);

	title("7. Copia e assegnazione");
	// source: robot di partenza. copy nasce da source (costruttore di copia).
	// target esiste gia' e viene sovrascritto con i valori di source (operator=).
	ClapTrap	source("Bender");
	source.attack("R2-D2");
	source.takeDamage(3);
	std::cout << "-> copy nasce da source:" << std::endl;
	ClapTrap	copy(source);
	ClapTrap	target("C-3PO");
	std::cout << "-> target = source (ora hanno lo stesso nome):" << std::endl;
	target = source;
	std::cout << "-> source subisce 2 danni (la copia non deve cambiare):" << std::endl;
	source.takeDamage(2);
	std::cout << "-> copy si ripara di 1:" << std::endl;
	copy.beRepaired(1);
	ClapTrap	&same = target;
	std::cout << "-> auto-assegnazione:" << std::endl;
	target = same;		// auto-assegnazione, passando da un riferimento

	title("Fine: i distruttori partono in ordine inverso");
	return (0);
}
