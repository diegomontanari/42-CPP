#include "Zombie.hpp"

/*
 la stessa differenza che hai in C tra . e ->:

se hai l’oggetto in una variabile (come in randomChump), usi il punto: zombieScrollatore.announce();
se hai un puntatore all’oggetto, usi la freccia: p->announce();
newZombie restituisce uno Zombie*, cioè un puntatore, quindi nel main scrivi:
*/
int main(void)
{
	// lavoro dello zombie che vive nell'heap (memoria dinamica)
	Zombie *z1 = newZombie("Zombie che vive nell'heap");
	z1->announce();
	delete z1;	
	
	// lavoro dello zombie che vive nello stack (memoria automatica, non statica)
	randomChump("Zombie che vive nello stack");
}
