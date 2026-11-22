#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap 
{
	public: 
	
	// costruttore di default (se chiami ClapTrap a;)
	ClapTrap();

	// costruttore con nome (se chiami ClapTrap a("Diego");)	
	ClapTrap(const std::string &name);

	// costruttore di copia
	ClapTrap(const ClapTrap &other);

	// operatore di assegnazione
	ClapTrap &operator=(const ClapTrap &other);

	/*
	Ricordatelo così: nella firma ClapTrap &operator=(const ClapTrap &other) ci sono due & con due scopi.

	La prima (davanti a operator=): "restituisco l'oggetto stesso, non una copia".
	La seconda (nel parametro): "ricevo l'originale, non una copia", e il const promette che non lo modifico.
	*/

	~ClapTrap();
	
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	private:

	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;


};


#endif
