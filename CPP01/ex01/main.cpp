#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int		N = 5;
	Zombie	*horde = zombieHorde(N, "Zombie dell'orda");

	if (!horde)
		return (1);
	// horde[i] è lo zombie numero i dell'array: è un oggetto, quindi il punto
	for (int i = 0; i < N; i++)
		horde[i].announce();
	// delete[] con le quadre: chiama il distruttore di tutti gli N, poi libera il blocco
	delete[] horde;
	return (0);
}
