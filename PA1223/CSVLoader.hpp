#ifndef CSVLOADER_HPP
#define CSVLOADER_HPP
#include "List.hpp"
#include "Data.hpp"
#include <fstream>
#include <iostream>

void loadFromCSV(List<Data>& commandList, const std::string& infile);




#endif // !CSVLOADER_HPP
