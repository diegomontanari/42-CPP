#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0; // this è il puntatore all'oggetto che stai utilizzando
			  // avrei potuto tranquillamente scrivere Fixed::Fixed() : _value(0) 
			  // usando la lista di inizializzazione e risparmiarmi questa riga
}

/*
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
_value = 0 dentro il corpo funziona uguale per un int, ma la lista è più giusta perché il membro nasce già con il valore, invece di nascere con un valore a caso e poi essere sovrascritto. Nel 42 va benissimo in entrambi i modi: scegli quella che capisci meglio, l’importante è saperla spiegare.

2. this-> è un’abitudine, non una necessità. Come già visto con Zombie, _value da solo significa già this->_value: this è il puntatore all’oggetto su cui stai lavorando, e dentro una funzione membro il C++ lo aggiunge da solo. Lo scrivi esplicito solo quando serve davvero (per esempio return (*this);, dove devi restituire l’oggetto stesso, o quando un nome è ambiguo).
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; //other è un 
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

/*
Perché serve *this e non this e basta?

this è un puntatore (Fixed *), ma operator= lavora con oggetti, non con puntatori:

this = other; → sbagliato: proveresti ad assegnare un oggetto a un puntatore. Non compila.
*this = other; → giusto: *this è l’oggetto stesso (hai “aperto” il puntatore con l’asterisco), quindi stai dicendo “l’oggetto che sono io = other”.

Il compilatore lo traduce in this->operator=(other), cioè chiama l’assegnazione su di te. Per questo partono i due messaggi di fila.

Lo stesso vale in return (*this);: la funzione deve restituire un Fixed & (un oggetto), non un puntatore, quindi dereferenzi.

Regola da ricordare: this = indirizzo, *this = l’oggetto che c’è a quell’indirizzo. Come con un int *p, dove p è l’indirizzo e *p il numero.
*/

/*
Quante volte devo scrivere &operator=() ? Perché non basta il semplice a = b del C?

lo scrivi una volta sola per classe, poi a = b; funziona ovunque.

Perché esiste, se in C basta a = b? In C la copia di una struct copia i byte uno a uno, e finché dentro ci sono solo numeri va benissimo. Il problema nasce quando l’oggetto contiene un puntatore a memoria sul heap. Esempio:

class Brain { char *_ideas; ... };   // _ideas punta a memoria presa con new
Brain a;
Brain b;
b = a;     // copia dei byte: ora b._ideas e a._ideas puntano alla STESSA memoria

Quando a e b muoiono, entrambi fanno delete sulla stessa memoria: crash. Succede uguale in C con una struct che ha un char *. In C++ puoi risolverlo scrivendo tu operator=: invece di copiare il puntatore, allochi nuova memoria e copi il contenuto (la cosiddetta copia profonda). In CPP04 lo farai davvero.

Quindi, per essere chiari:

- Copia superficiale (shallow copy)
- Copia profonda (deep copy)

Superficiale: copi i valori così come sono, quindi se dentro c’è un puntatore copi solo l’indirizzo. I due oggetti condividono la stessa memoria. È quello che fa la copia automatica del C e del C++.
Profonda: copi anche quello a cui il puntatore punta. Alloci una nuova memoria e ci copi dentro il contenuto, così ogni oggetto ha la sua.

E per Fixed? Dentro c’è solo un int, quindi la copia automatica basterebbe e non avresti bisogno di scriverla. Il subject te la fa scrivere adesso per farti vedere il meccanismo (per questo stampa i messaggi) e per abituarti alla forma canonica, che userai in tutti i moduli dopo.
*/
