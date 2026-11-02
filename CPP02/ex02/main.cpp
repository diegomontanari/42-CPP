#include <iostream>
#include "Fixed.hpp"

// main di test del subject (CPP02, ex02), seguito da qualche test in più
int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "--- test in più ---" << std::endl;
	Fixed	x(10);
	Fixed	y(2.5f);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;
	std::cout << "x > y: " << (x > y) << ", x < y: " << (x < y) << ", x == x: " << (x == x) << ", x != y: " << (x != y) << std::endl;
	std::cout << "x >= y: " << (x >= y) << ", x <= y: " << (x <= y) << std::endl;
	std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
	// una modifica per riga: in una stessa catena di << l'ordine di valutazione
	// non è garantito in C++98, quindi non si mescolano --y e y-- nella stessa riga
	std::cout << "--y = " << --y << std::endl;
	std::cout << "y-- = " << y-- << std::endl;
	std::cout << "y = " << y << std::endl;
	return (0);
}
