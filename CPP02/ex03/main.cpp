#include <iostream>
#include "Point.hpp"

// Test del subject: "implement and turn in your own tests"
static void	test(const char *label, Point const &p, bool expected)
{
	Point const	a(0.0f, 0.0f);
	Point const	b(10.0f, 0.0f);
	Point const	c(0.0f, 10.0f);
	bool		result = bsp(a, b, c, p);

	std::cout << (result == expected ? "OK  " : "KO  ") << label
		<< " -> " << (result ? "dentro" : "fuori") << std::endl;
}

int	main(void)
{
	std::cout << "Triangolo: (0,0) (10,0) (0,10)" << std::endl;
	test("(1, 1) chiaramente dentro", Point(1.0f, 1.0f), true);
	test("(3, 3) dentro", Point(3.0f, 3.0f), true);
	test("(0.5, 0.5) dentro, vicino a un vertice", Point(0.5f, 0.5f), true);
	test("(6, 6) fuori, oltre l'ipotenusa", Point(6.0f, 6.0f), false);
	test("(-1, 1) fuori a sinistra", Point(-1.0f, 1.0f), false);
	test("(5, 0) sul lato in basso", Point(5.0f, 0.0f), false);
	test("(5, 5) sull'ipotenusa", Point(5.0f, 5.0f), false);
	test("(0, 0) su un vertice", Point(0.0f, 0.0f), false);
	test("(10, 0) su un vertice", Point(10.0f, 0.0f), false);
	return (0);
}
