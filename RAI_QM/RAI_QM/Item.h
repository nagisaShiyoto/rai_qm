#pragma once
#include <iostream>
#include <vector>
class Item
{
public:

	//---------//
	// getters //
	//---------//
	std::vector<std::string>  getProperties() const;
	std::string getName() const;

	//---------//
	// setters //
	//---------//
	void setName(const std::string name);
	void addProperty(const std::string property);

	//---------//
	// methods //
	//---------//
	bool search(std::string property);
	Item(std::string name, std::vector<std::string> properties);

private:
	std::string _name;
	std::vector<std::string> _properties;
};

