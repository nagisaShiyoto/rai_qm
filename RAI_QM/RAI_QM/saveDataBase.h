#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
class saveDataBase
{
public:
	static std::vector<std::string> _allProperties;
	static std::vector<Item*> _allItems;
	static void addItem(std::vector<std::string> properties);
};

