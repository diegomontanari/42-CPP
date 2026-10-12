#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
	// Il costruttore deve ricevere il nome, altrimenti lo zombie nasce senza nome
	Zombie(const std::string &name);
	// ex01: new Zombie[N] chiama per ognuno il costruttore SENZA argomenti,
	// quindi serve Zombie(); il nome si dà dopo, con setName
	Zombie();
	~Zombie();
	void announce(void);
	void setName(const std::string &name);
	private:
	std::string _name;
};

// Crea N zombie con un'unica allocazione e restituisce il puntatore al primo
Zombie* zombieHorde(int N, std::string name);

#endif
