#include "Debug.h"

std::vector<std::string> Debug::getItemData(std::string filePath, std::string name)
{
	std::vector<std::string> properties;
	std::vector<Item*> items;

	FileHelper::getData(properties, items, filePath);

	for (int i = 0; i < items.size(); i++)
	{
		if (name == items[i]->getName())
		{
			return items[i]->getProperties();
		}
	}

	throw("ERROR: name not found");
}
