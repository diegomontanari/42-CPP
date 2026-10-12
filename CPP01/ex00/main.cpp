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

/*
Appunto su new e delete:

delete fa due cose, in quest’ordine, su un oggetto creato con new:

chiama il distruttore dell’oggetto (nel nostro caso stampa “... Is destroyed”);
libera la memoria dell’heap, come farebbe free.

È il contrario di new, che alloca e poi chiama il costruttore. In C era malloc ↔ free, qui new ↔ delete. Se te ne dimentichi, la memoria resta occupata (leak) e il distruttore non parte mai: per questo nell’ex00 vedevi “Is destroyed” dello zombie dell’heap solo grazie alla delete.

Lo stack invece non ha bisogno di delete: a fine blocco ci pensa il compilatore.

Tre regole su delete da tenere a mente, che completano quello che ti ho detto:

ogni new si chiude con una delete: né zero (leak) né due (double free, crash);
dopo la delete il puntatore non è più tuo: non lo usare più, z1->announce() dopo la delete è comportamento indefinito;
per gli array creati con new Zombie[N] si usa delete[], con le quadre: è quello che vedrai ora nell’ex01.

Per questo in C++ sugli oggetti non si usano malloc e free: malloc non chiama il costruttore e free non chiama il distruttore.
*/
