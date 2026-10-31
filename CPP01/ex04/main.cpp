#include <fstream>	// std::ifstream, std::ofstream: i file come stream
#include <sstream>	// std::stringstream: per leggere tutto il file in una stringa
#include <string>
#include <iostream>

// Sostituisce ogni occorrenza di s1 con s2 dentro text, senza std::string::replace.
// Idea: cerco s1 con find, copio nel risultato il pezzo prima, aggiungo s2,
// e riparto a cercare subito dopo s1. Quando find non trova più niente, copio il resto.
static std::string	replaceAll(const std::string &text, const std::string &s1, const std::string &s2)
{
	std::string			result;
	std::string::size_type	start = 0;
	std::string::size_type	pos = text.find(s1, start);

	while (pos != std::string::npos)
	{
		result += text.substr(start, pos - start);	// il pezzo prima di s1
		result += s2;					// al posto di s1 metto s2
		start = pos + s1.length();			// riparto dopo s1
		pos = text.find(s1, start);
	}
	result += text.substr(start);				// quello che resta dopo l'ultima s1
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	// 1. s1 vuota: non c'è niente da cercare (e find troverebbe s1 ovunque, all'infinito)
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}

	// 2. Leggo tutto il file in una stringa
	std::ifstream	in(filename.c_str());	// in C++98 ifstream vuole un const char *, da qui c_str()
	if (!in)
	{
		std::cerr << "Error: cannot open " << filename << std::endl;
		return (1);
	}
	std::stringstream	buffer;
	buffer << in.rdbuf();			// "versa" tutto il contenuto del file nello stringstream
	std::string	content = buffer.str();
	in.close();

	// 3. Sostituisco
	std::string	replaced = replaceAll(content, s1, s2);

	// 4. Scrivo il risultato in filename.replace
	std::string	outname = filename + ".replace";
	std::ofstream	out(outname.c_str());
	if (!out)
	{
		std::cerr << "Error: cannot create " << outname << std::endl;
		return (1);
	}
	out << replaced;
	out.close();
	return (0);
}
