#include "Fixed.hpp"
#include <cmath>	// roundf, l'unica funzione permessa in più dal subject

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;	// riusa l'operatore di assegnazione
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Da int a Fixed: moltiplico per 256 spostando i bit di 8 posti a sinistra.
// 10 diventa 10 << 8 = 2560
Fixed::Fixed(const int n) : _value(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// Da float a Fixed: moltiplico per 256 e arrotondo all'intero più vicino.
// 42.42 * 256 = 10859.52, che roundf porta a 10860.
// (Sui float non si può usare <<: lo shift esiste solo per gli interi)
Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// Nessun messaggio qui: in ex01 l'output atteso del subject non lo mostra
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// Da Fixed a float: divido per 256. Il cast (float) rende la divisione tra float;
// tra due interi sarebbe una divisione intera e perderei i decimali.
float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fractionalBits));
}

// Da Fixed a int: sposto i bit di 8 posti a destra, buttando la parte decimale.
// 2560 >> 8 = 10
int Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

// std::cout << a  diventa  operator<<(std::cout, a).
// Scrivo nello stream la versione float del numero e restituisco lo stream,
// così si possono concatenare altri <<, come in: std::cout << a << std::endl;
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
