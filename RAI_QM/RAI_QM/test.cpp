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
	FileHelper::saveData(properties, items);
	return 0;
}