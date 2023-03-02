#include "FileHelper.h"

std::vector<std::string> FileHelper::getProperties(int const num_of_properties, std::ifstream file)
{
    return std::vector<std::string>();
}

std::vector<Item> FileHelper::getItems(int const anount_of_items, std::ifstream file)
{
    return std::vector<Item>();
}

void FileHelper::getData(std::vector<std::string>& properties, std::vector<Item>& items)
{
    std::string fromFile = "";
    std::ifstream file(FILE_PATH);
    std::getline(file, fromFile);
    //fromFile.
}
