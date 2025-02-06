#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVLoader.hpp"

void loadFromCSV(List<Data>& commandList, const std::string& infile)
{

	std::ifstream file(infile);
	if (!file.is_open())
	{
		std::cerr << "Error opening file: " << infile << std::endl;
		return;

	}

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string key, value;
		int points;

		if (std::getline(ss, key, ',') && std::getline(ss, value, ',') && ss >> points)
		{
			commandList.insertAtFront(Data(key, value));
			
		}
		else
		{
			std::cerr<< "Error reading line: " << line << std::endl;
		}
	}
	file.close();
		std::cout << "Commands loaded successfully" << std::endl;

}
