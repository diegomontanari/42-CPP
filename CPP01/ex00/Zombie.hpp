#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
	// Il costruttore deve ricevere il nome, altrimenti lo zombie nasce senza nome
	Zombie(const std::string &name);
	~Zombie();
	void announce(void);
	private:
	std::string _name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
