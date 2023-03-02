#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
#include <fstream>
#include <string>
#define FILE_PATH "idk"
class FileHelper
{
public:
	static std::vector<std::string> getProperties(int const num_of_properties, std::ifstream file);
	static std::vector<Item> getItems(int const anount_of_items, std::ifstream file);
	static void getData(std::vector<std::string>& properties, std::vector<Item>& items);
};