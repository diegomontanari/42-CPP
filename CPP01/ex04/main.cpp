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

	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}

	// read the whole file into a string
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: cannot open " << filename << std::endl;
		return (1);
	}
	std::stringstream buffer;
	buffer << inFile.rdbuf();
	std::string content = buffer.str();
	inFile.close();

	// replace every occurrence of s1 with s2 (without std::string::replace)
	std::string result;
	std::string::size_type pos = 0;
	std::string::size_type found;
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos, std::string::npos);

	// write to filename.replace
	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: cannot create " << filename << ".replace" << std::endl;
		return (1);
	}
	outFile << result;
	outFile.close();

	return (0);
}