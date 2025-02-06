#ifndef DATA_HPP
#define DATA_HPP

#include <string>
class Data {
public:
	std::string key;
	std::string value;
	Data(std::string k = "", std::string v = "") : key(k), value(v) {};
};

#endif