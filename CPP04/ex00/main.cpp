#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "===== Subject test (virtual makeSound) =====" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "===== Wrong test (NON virtual makeSound) =====" << std::endl;
	const WrongAnimal *wrong = new WrongCat();

	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound(); // WrongAnimal sound: no polymorphism
	delete wrong;

	std::cout << std::endl << "===== WrongCat used directly =====" << std::endl;
	WrongCat wc;
	wc.makeSound(); // here the static type is WrongCat: WrongCat sound

	std::cout << std::endl << "===== Copies (Orthodox Canonical Form) =====" << std::endl;
	Dog a;
	Dog b(a);
	Cat c;
	Cat d;
	d = c;
	std::cout << b.getType() << " / " << d.getType() << std::endl;
	return (0);
}
