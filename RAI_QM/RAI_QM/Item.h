#pragma once
#include <iostream>
#include <vector>
class Item
{
public:
	//getters:
	std::vector<std::string>  getProperties()const;
	std::string getName()const;
	//setters:
	void setName(const std::string name);
	void addProperty(const std::string property);
	void deleteProperties(const std::string property);
	//method
	bool search(std::string property);
	Item(std::string name);
private:
	std::string _name;
	std::vector<std::string> _properties;
};

