#include "saveDataBase.h"
#include <unordered_set>
std::vector<std::string> saveDataBase::_allProperties;
std::vector<Item*> saveDataBase::_allItems;
std::vector<std::string> remove(std::vector<std::string> v)
{
    std::vector<std::string>::iterator itr = v.begin();
    std::unordered_set<std::string> s;

    for (auto curr = v.begin(); curr != v.end(); ++curr)
    {
        if (s.insert(*curr).second) {
            *itr++ = *curr;
        }
    }

    v.erase(itr, v.end());
    return v;
}
void saveDataBase::addItem(std::string name, std::vector<std::string> properties)
{
	bool found = false;
	for (int i = 0; i < saveDataBase::_allItems.size(); i++)
	{
		if (name == saveDataBase::_allItems[i]->getName())
		{
			found = true;
            for (int j = 0; j < properties.size(); j++)
            {
                saveDataBase::_allItems[i]->addProperty(properties[j]);
            }
            saveDataBase::_allItems[i]->setProperty(remove(saveDataBase::_allItems[i]->getProperties()));
		}
	}
    if (!found&&properties.size()>=1)
    {
        Item* item = new Item(name, properties);
        saveDataBase::_allItems.push_back(item);
    }
}

void saveDataBase::addProperties(std::string property)
{
    bool found = false;
    for (auto it = saveDataBase::_allProperties.begin(); it != saveDataBase::_allProperties.end(); it++)
    {
        if (property == *it)
        {
            found = true;
        }
    }
    if (!found)
    {
        saveDataBase::_allProperties.push_back(property);
    }
}
