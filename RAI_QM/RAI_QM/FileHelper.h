#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
#include <fstream>
#include <string>
class FileHelper
{
public:
	static std::vector<std::string> txt;
	static void getData(std::vector<std::string>& properties, std::vector<Item*>& items, std::string filePath = "../exemples/empty.txt");
	static void saveData(std::vector<std::string>& properties, std::vector<Item*>& items, std::string filePath = "../exemples/empty.txt");
private:
	static std::vector<std::string> getProperties(int const num_of_properties);
	static std::vector<Item*> getItems(int const anount_of_items);
	static void saveProperties(std::vector<std::string> const properties);
	static void saveItems(std::vector<Item*> const items);
};