#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// TODO: check s1 empty

	// TODO: read file into string

	// TODO: replace all occurrences of s1 with s2

	// TODO: write to filename.replace

	return (0);
}