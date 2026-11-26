#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// AAnimal a;              // errore di compilazione: classe astratta
	// AAnimal *p = new AAnimal(); // idem

	std::cout << "===== Subject test =====" << std::endl;
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	delete j; // no leak
	delete i;

	std::cout << std::endl << "===== Array of Animals (half Dog, half Cat) =====" << std::endl;
	const int N = 6;
	AAnimal *animals[N];
	for (int k = 0; k < N; k++)
	{
		if (k < N / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	for (int k = 0; k < N; k++)
		animals[k]->makeSound();
	for (int k = 0; k < N; k++)
		delete animals[k]; // ogni delete passa dal distruttore virtuale

	std::cout << std::endl << "===== Deep copy test =====" << std::endl;
	Dog original;
	original.getBrain()->setIdea(0, "I want a bone");
	{
		Dog copy(original); // copy constructor
		copy.getBrain()->setIdea(0, "I want a walk");
		std::cout << "original: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "copy:     " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "brain pointers differ: "
			<< (original.getBrain() != copy.getBrain() ? "yes" : "no") << std::endl;
	}
	std::cout << "original after copy destroyed: "
		<< original.getBrain()->getIdea(0) << std::endl;

	Cat c1;
	Cat c2;
	c1.getBrain()->setIdea(0, "I want fish");
	c2 = c1; // copy assignment
	c1.getBrain()->setIdea(0, "I want to sleep");
	std::cout << "c1: " << c1.getBrain()->getIdea(0) << std::endl;
	std::cout << "c2: " << c2.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "===== Wrong test (non virtual) =====" << std::endl;
	const WrongAnimal *wrong = new WrongCat();
	wrong->makeSound(); // WrongAnimal sound: no polymorphism
	delete wrong;
	return (0);
}
