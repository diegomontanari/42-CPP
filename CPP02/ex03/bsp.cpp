#include "Point.hpp"

// Da che parte del lato p1 -> p2 sta il punto p?
// È il "prodotto vettoriale" in 2D:
//   (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) * (p.x - p1.x)
// positivo = p sta a sinistra del lato, negativo = a destra, zero = sulla retta.
static Fixed	side(Point const &p1, Point const &p2, Point const &p)
{
	return ((p2.getX() - p1.getX()) * (p.getY() - p1.getY())
		- (p2.getY() - p1.getY()) * (p.getX() - p1.getX()));
}

// Il punto è dentro il triangolo se sta dalla STESSA parte di tutti e tre i lati.
// Se uno dei tre valori è zero, il punto è su un lato (o su un vertice):
// il subject vuole false anche in quel caso.
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1 = side(a, b, point);
	Fixed	d2 = side(b, c, point);
	Fixed	d3 = side(c, a, point);
	Fixed	zero(0);

	if (d1 == zero || d2 == zero || d3 == zero)
		return (false);
	bool	allPositive = (d1 > zero && d2 > zero && d3 > zero);
	bool	allNegative = (d1 < zero && d2 < zero && d3 < zero);
	return (allPositive || allNegative);
}
