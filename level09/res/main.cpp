#include <iostream>
#include <fstream>

int main()
{
	std::ifstream	file;
	std::string		content;
	file.open("./test.txt");
	file >> content;
	for (int i = 0; i < content.length(); i++)
		content[i] = content[i] - i;
	std::cout << content << std::endl;
}