#include "Fixed.hpp"
#include <cmath>

// In ex02 i messaggi dei costruttori sono tolti: il subject mostra l'output
// "senza i messaggi di costruttori e distruttori", per leggibilità.

/* ---------- Forma canonica e conversioni (come ex01) ---------- */

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &other) : _value(other._value) {}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed() {}

Fixed::Fixed(const int n) : _value(n << _fractionalBits) {}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits))) {}

int		Fixed::getRawBits(void) const { return (this->_value); }
void	Fixed::setRawBits(int const raw) { this->_value = raw; }
float	Fixed::toFloat(void) const { return ((float)this->_value / (1 << _fractionalBits)); }
int		Fixed::toInt(void) const { return (this->_value >> _fractionalBits); }

/* ---------- Confronti ---------- */
// Due Fixed hanno la stessa "scala" (tutti moltiplicati per 256), quindi per
// confrontarli basta confrontare i valori grezzi.

bool	Fixed::operator>(const Fixed &other) const { return (this->_value > other._value); }
bool	Fixed::operator<(const Fixed &other) const { return (this->_value < other._value); }
bool	Fixed::operator>=(const Fixed &other) const { return (this->_value >= other._value); }
bool	Fixed::operator<=(const Fixed &other) const { return (this->_value <= other._value); }
bool	Fixed::operator==(const Fixed &other) const { return (this->_value == other._value); }
bool	Fixed::operator!=(const Fixed &other) const { return (this->_value != other._value); }

/* ---------- Aritmetica ---------- */
// Restituiscono un Fixed nuovo: a + b non deve modificare né a né b.

// Somma e sottrazione: stessa scala, quindi si sommano i grezzi.
// (a*256) + (b*256) = (a+b)*256: il risultato è già nella scala giusta.
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->_value - other._value);
	return (result);
}

// Prodotto e divisione: con i grezzi la scala si sbaglia, quindi si passa dai
// float. (a*256) * (b*256) = a*b*65536: verrebbe moltiplicato una volta di troppo.
Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

// Dividere per zero: il subject accetta che il programma crashi.
Fixed	Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

/* ---------- Incremento e decremento ---------- */
// Il passo è il numero più piccolo rappresentabile, epsilon = 1/256: in grezzo vale 1.

// ++a: incrementa e restituisce l'oggetto stesso, già incrementato
Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

// a++: si salva una copia del valore VECCHIO, incrementa, e restituisce la copia.
// Per questo restituisce per copia e non per riferimento.
Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	this->_value++;
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	this->_value--;
	return (old);
}

/* ---------- min e max ---------- */
// Due versioni ciascuna: una per Fixed modificabili, una per Fixed const.
// Restituiscono un riferimento a uno dei due argomenti, non una copia.

Fixed	&Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) { return (a < b ? a : b); }
Fixed	&Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) { return (a > b ? a : b); }

/* ---------- Stampa ---------- */

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
