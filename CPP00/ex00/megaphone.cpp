#include <iostream>	// std::cout, std::endl
#include <cctype>	// std::toupper

int	main(int argc, char **argv)
{
	// argc == 1 significa che c'è solo il nome del programma, nessun argomento
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	// Partiamo da 1 perché argv[0] è "./megaphone"
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			// Il cast a unsigned char evita comportamenti indefiniti con
			// caratteri non ASCII (valori negativi); il risultato è un int,
			// quindi lo riconvertiamo in char per stamparlo come carattere.
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
		}
	}
	// Nessuno spazio tra gli argomenti: solo l'a capo finale
	std::cout << std::endl;
	return (0);
}
