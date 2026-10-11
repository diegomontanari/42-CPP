#include "Zombie.hpp"

// Niente soluzione, ma due indizi. Pensa a come dichiari una variabile qualsiasi, per esempio int x = 5;: il tipo, il nome della variabile, il valore iniziale.

// Per un oggetto è uguale, solo che il valore iniziale non si mette con = ma tra parentesi dopo il nome, e va al costruttore. L’esempio l’abbiamo già visto nell’approfondimento su Zombie z("Foo").

/*
Quindi cosa fa Zombie zombieScrollatore(name); ?
“Crea sullo stack uno Zombie, chiamalo zombieScrollatore, e costruiscilo usando il nome ricevuto (name).”

Zombie: il tipo, cioè “uno zombie”;
zombieScrollatore: il nome della variabile, quello che usi nel codice (zombieScrollatore.announce(););
(name): l’argomento che va al costruttore, che lo salva in _name.

Occhio ai due “nomi”: zombieScrollatore è il nome della variabile, per il codice; name (per esempio “Bob”) è il nome dello zombie, quello che announce stampa a schermo. È come int eta = 30;: eta è la variabile, 30 il valore.
*/
void randomChump(std::string name)
{
	Zombie zombieScrollatore(name);
	zombieScrollatore.announce();
}
