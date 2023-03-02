#include "Helper.h"
#include "FileHelper.h"
#include "Item.h"
#include <iostream>
#include <vector>
int main()
{
	std::vector<std::string> properties;
	std::vector<Item*> items;
	FileHelper::getData(properties, items);
	for (auto it = properties.begin(); it != properties.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	for (auto it = items.begin(); it != items.end(); it++)
	{
		std::cout << (*it)->getName()<<":";
		auto prop = (*it)->getProperties();
		for (auto pt=prop.begin(); pt != prop.end(); pt++)
		{
			std::cout << *pt<<",";
		}
		std::cout << std::endl;
	}
	return 0;
}