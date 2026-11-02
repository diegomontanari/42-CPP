#include "Point.hpp"

// _x e _y sono const: si possono impostare SOLO nella initialization list,
// mai con un'assegnazione nel corpo. È il caso in cui la lista è obbligatoria.
Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

// L'assegnazione non può cambiare _x e _y, perché sono const: non c'è niente
// da copiare. La forma canonica la richiede comunque, quindi esiste ma lascia
// il punto com'è. (Per "spostare" un punto se ne crea uno nuovo.)
Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point() {}

Fixed	Point::getX(void) const { return (this->_x); }
Fixed	Point::getY(void) const { return (this->_y); }
