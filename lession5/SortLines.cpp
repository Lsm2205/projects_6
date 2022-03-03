#include <string>
#include <iostream>
#include <sstream>
#include <map>

void SortLines()
{
	std::multimap<int, std::string> lines;
	std::string userInput = "";
	std::getline(std::cin, userInput);
	std::stringstream ss(userInput);

	while (ss.good())
	{
		std::string buffer;
		std::getline(ss, buffer, '.');
		if (buffer[buffer.length()-1] == 0) lines.insert(std::make_pair(buffer.length() - 1, buffer));
		else lines.insert(std::make_pair(buffer.length(), buffer));
	}
	std::cout << "Sorted lines:\n";
	for (const auto& line : lines)
	{
		if (line.first != 0) std::cout << line.second << std::endl;
	}
}
