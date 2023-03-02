#include "FileHelper.h"
#include"Helper.h"
#include "Item.h"
#define START_LINE 3
std::vector<std::string> FileHelper::txt;

std::vector<std::string> FileHelper::getProperties(int const num_of_properties)
{
    std::vector<std::string> all_prop = Helper::split(",", txt[1]);
    std::vector<std::string> prop;
    for (int i = 0; i < num_of_properties; i++)
    {
        prop.push_back(all_prop[i]);
    }
    return prop;
}

std::vector<Item*> FileHelper::getItems(int const amount_of_items)
{
    std::vector<Item*> items;
    std::vector < std::string> splitString;
    std::string name = "";
    for (int i = START_LINE; i < amount_of_items+START_LINE; i++)
    {
        splitString = Helper::split(":", txt[i]);
        name = splitString[0];
        splitString = Helper::split(",", splitString[1]);
        items.push_back(new Item(name, splitString));
    }
    return items;
}

void FileHelper::getData(std::vector<std::string>& properties, std::vector<Item*>& items)
{
    //////////////////////////////get all the text from file//////////////////////////
    std::ifstream file(FILE_PATH);
    std::string line = "";
    while (std::getline(file, line))
    {
        FileHelper::txt.push_back(line);
    }
    file.close();
    //////////////////////////////get all the text from file//////////////////////////
    std::vector<std::string> amounts = Helper::split(",", txt[0]);
    properties = FileHelper::getProperties(atoi(amounts[1].c_str()));
    items = FileHelper::getItems(atoi(amounts[0].c_str()));
}

void FileHelper::saveData(std::vector<std::string>& properties, std::vector<Item*>& items)
{
    ///////////////////////////////////get all the info to vector//////////////////////////////////////////
    //clear for txt
    txt.clear();
    std::string line = "";
    line = std::to_string(items.size()) + "," + std::to_string(properties.size());
    txt.push_back(line);
    FileHelper::saveProperties(properties);
    txt.push_back("");
    FileHelper::saveItems(items);
    ///////////////////////////////////get all the info to vector//////////////////////////////////////////
    /////////////////////////////////////////write to file/////////////////////////////////////////////////
    std::ofstream file(FILE_PATH);
    for (auto it = txt.begin(); it != txt.end(); it++)
    {
        file << *it << std::endl;
    }
    /////////////////////////////////////////write to file/////////////////////////////////////////////////
}

void FileHelper::saveProperties(std::vector<std::string> const properties)
{
    std::string line = Helper::join(",", properties);
    txt.push_back(line);
}

void FileHelper::saveItems(std::vector<Item*> const items)
{
    std::string line = "";
    for (auto it = items.begin(); it != items.end(); it++)
    {
        line = (*it)->getName() + ":" + Helper::join(",", (*it)->getProperties());
        txt.push_back(line);
    }
}
