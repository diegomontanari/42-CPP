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

/*
Come fa delete[] a liberare la memoria di tutti senza essere in un ciclo?

Quando fai new Zombie[N], il C++ si ricorda in qualche modo il numero N, tipicamente salvandolo in un piccolo campo nascosto subito prima del blocco di memoria (il dettaglio dipende dal compilatore, e non devi gestirlo tu). Quando fai delete[] horde, legge quel numero e genera internamente qualcosa come: chiama il distruttore su ognuno degli N elementi, poi libera il blocco con un’unica operazione.

Perché servono le quadre. Con delete horde (senza quadre) il compilatore non cerca quel numero: chiama il distruttore su un solo oggetto, il primo, e prova a liberare il blocco come se fosse un singolo. Gli altri N-1 zombie non vengono distrutti e il comportamento è indefinito, quindi può anche andare in crash. Ricordati la regola: new[] va sempre chiuso da delete[].

Come lo vedi nel tuo programma. Se ogni distruttore stampa il nome, con delete[] vedi N messaggi Is destroyed, uno per zombie. Prova a togliere le quadre e confronta cosa stampa: ti conviene farlo una volta, ma solo per capire. Poi rimettile.
*/
