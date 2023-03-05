#include "Item.h"

/*
the func returns the Items properties as a vector
input: none
output: the properties (vector<string>)
*/
std::vector<std::string> Item::getProperties() const
{
	return this->_properties;
}

/*
the func returns the Items name
input: none
output: the Items name (string)
*/
std::string Item::getName() const
{
	return this->_name;
}

/*
the func changes the items name to a given name
input: the new name (string)
output: none
*/
void Item::setName(const std::string name)
{
	this->_name = name;
}

/*
the func adds a property to the properties
input: the property (string)
output: none
*/
void Item::addProperty(const std::string property)
{
	this->_properties.push_back(property);
}

void Item::setProperty(std::vector<std::string> propeties)
{
	this->_properties = propeties;
}

/*
the func checks if the Item has a given property
input: the property (string)
output: if the property was found (bool)
*/
bool Item::search(std::string property)
{
	for (int i = 0; i < _properties.size(); i++)
	{
		if (property == this->_properties[i])
		{
			return true;
		}
	}

	return false;
}

/*
a constractor to Item with given name and properties
input: this name (string), the properties (vector<string>)
output: none
*/
Item::Item(std::string name, std::vector<std::string> properties)
{
	this->_name = name;
	this->_properties = properties;
}
