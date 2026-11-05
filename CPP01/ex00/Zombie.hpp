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

/*

& lì nel costruttore non è “indirizzo di”, è un riferimento. Nelle dichiarazioni, & dopo il tipo (std::string &name) significa “name è un altro nome per una stringa che esiste già”. 
L’operatore indirizzo (&x) si usa invece nelle espressioni, davanti a una variabile.

Perché lo si usa qui?

Se scrivessi Zombie(std::string name), a ogni chiamata la stringa verrebbe copiata per costruire il parametro, e poi copiata di nuovo in _name. Due copie.

Per capirlo, esempio. Seguiamo Zombie z("Bob"); con il costruttore Zombie(std::string name) : _name(name).

Prima copia, per costruire il parametro. Quando chiami il costruttore, name è una variabile nuova, che vive dentro il costruttore. Per esistere deve avere un contenuto, quindi C++ la costruisce copiando la stringa che hai passato (“Bob”). Quello è il passaggio per valore.
Seconda copia, nella lista di inizializzazione. _name(name) costruisce l’attributo _name della classe a partire da name. È un’altra stringa, che resta nello zombie, quindi si copia di nuovo il contenuto.

Alla fine ci sono tre stringhe in memoria: l’originale, name (che sparisce a fine costruttore) e _name. La seconda esiste solo di passaggio.

Con const std::string &name la funzione lavora direttamente sulla stringa di chi chiama, senza copiarla. Poi _name(name) fa l’unica copia necessaria, nella lista di inizializzazione.

In pratica: per oggetti “grossi” come std::string si passa per const & per non copiarli. Per tipi piccoli come int si passa per valore.
Con const std::string &name la copia 1 sparisce: name è solo un altro nome per la stringa originale, non una variabile nuova. Resta la copia 2, che serve davvero perché lo zombie deve possedere il suo nome.

Piccola precisazione: per stringhe corte e con compilatori moderni la differenza è minima, ma in C++98 e in generale per i tipi grossi è una buona abitudine.

Domanda di verifica per te: nel tuo codice newZombie e randomChump ricevono invece std::string name per valore, come chiede il subject (prototipi fissi). Quante copie della stringa si fanno in randomChump("Bob"), dal letterale fino a _name?

Il letterale è il "Bob" scritto tra virgolette nel codice. Non è un std::string: è un array di caratteri const char[4] (B, o, b, \0) che sta già nel programma, fisso, senza che nessuno lo copi. Quando lo passi a una funzione che vuole uno std::string, C++ deve costruire una stringa nuova a partire da quei caratteri. Intendevo contare le copie da lì.

Il conteggio, per randomChump("Bob")

randomChump(std::string name) prende il parametro per valore, quindi nasce uno std::string name costruito dai caratteri di "Bob". Prima stringa.
Dentro fai Zombie zombieScrollatore(name);. Il costruttore ha const std::string &name, quindi è un riferimento: nessuna copia.
Nella lista di inizializzazione, _name(name) costruisce l’attributo. Seconda stringa, l’unica che resta nello zombie.

In totale 2 stringhe costruite: quella nel parametro di randomChump e _name. Se anche il costruttore prendesse std::string name per valore, sarebbero 3. Il const & ne evita una.

Nota: questo conteggio è il modello semplice, che ti serve in eval. I compilatori possono saltare alcune copie con ottimizzazioni, ma in C++98 ragioni così.

*/
