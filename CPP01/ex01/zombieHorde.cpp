#include "Zombie.hpp"

// 1) new Zombie[N]: un unico blocco di N zombie sull'heap, creati col costruttore Zombie()
// 2) un ciclo dà a ognuno il nome con setName
// 3) restituisce il puntatore al primo: chi la chiama dovrà liberare tutto con delete[]
Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
