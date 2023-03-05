//#define GREEN 2
//#define DARK_RED 4
//#define PURPLE 5
//#define YELLOW 6
//#define LIGHT_BLUE 9
//#define LIGHT_GREEN 10
//#define TEAL 11
//#define RED 12
//#define PURPLE 13
//#define LIGHT_YELLOW 14
//#define WHITE 15
#include "Algorithm.h"
#include "saveDataBase.h"
#include <utility>
Algorithm::Algorithm(std::string filePath)
{
	this->_filePath = filePath;
	std::vector<std::string> properties;
	FileHelper::getData(properties, this->_items);
	for (auto it = properties.begin(); it != properties.end(); it++)
	{
		this->_propertyKey[*it] = 0;
	}
	for (auto it = this->_items.begin(); it != this->_items.end(); it++)
	{
		Item* item = *it;
		for (int i = 0; i < item->getProperties().size(); i++)
		{
			this->_propertyKey[item->getProperties()[i]]++;
		}
	}
	saveDataBase::_allItems = this->_items;
	saveDataBase::_allProperties = properties;
}
void addProperty(std::string name)
{
	std::vector<std::string> properties;
	bool con = true;
	std::string answer = "";
	answer = Helper::getAnswersFromUser("do you want to add property? (f/t)");
	con = Helper::toBool(answer);
	while (con)
	{
		std::cout << "what is the property? (animal, human, boy, girl etc...)" << std::endl;
		std::getline(std::cin, answer);
		saveDataBase::addProperties(answer);
		properties.push_back(answer);
		answer=Helper::getAnswersFromUser("do you want to add another property? (f/t)");
		con = Helper::toBool(answer);
	}
	saveDataBase::addItem(name, properties);
}


void Algorithm::playGame()
{
	std::vector<std::string> prop;
	bool present = false;
	std::string property = "";
	std::string answer = "";
	try
	{
		while (this->_items.size() > 1 && this->_propertyKey.size() != 0)
		{
			this->duplicates();
			property = this->getQuestion();
			answer = Helper::getAnswersFromUser("is it " + property + " (t/f)");
			present = Helper::toBool(answer);
			this->selection(present, property);
			if (present)
			{
				prop.push_back(property);
			}
		}
	}
	catch (const std::exception&)
	{
	}
	if (this->_items.size() == 0)
	{
		Helper::set_console_color(12);
		std::cout << "coudnt find item"<<std::endl;
		Helper::set_console_color(15);
	}
	else
	{
		bool found = false;
		for (auto it = this->_items.begin(); it != this->_items.end() && !found; it++)
		{
			Helper::set_console_color(2); // green
			std::cout << "=======================================================================================" << std::endl;
			answer = Helper::getAnswersFromUser("is it: " + (*it)->getName() + "?(t/f)");
			std::cout << "=======================================================================================" << std::endl;
			Helper::set_console_color(15); // white
			found = Helper::toBool(answer);
		}
		//if it got it right stop this fanction
		if (found)
		{
			addProperty(this->_items[0]->getName());
			return;
		}
	}
	std::cout << "who did you think about: ";
	std::getline(std::cin, answer);
	saveDataBase::addItem(answer, prop);
	addProperty(answer);

}

Algorithm::~Algorithm()
{
	FileHelper::saveData(saveDataBase::_allProperties, saveDataBase::_allItems, this->_filePath);
	this->_items.clear();
	this->_propertyKey.clear();
}

void Algorithm::setPropertyKey(std::vector<std::string> prop)
{
	for (auto it = prop.begin(); it != prop.end(); it++)
	{
		this->_propertyKey[*it] = 0;
	}
	for (auto it = this->_items.begin(); it != this->_items.end(); it++)
	{
		Item* item = *it;
		for (int i = 0; i < item->getProperties().size(); i++)
		{
			this->_propertyKey[item->getProperties()[i]]++;
		}
	}
}

void Algorithm::setItems(std::vector<Item*> items)
{
	this->_items = items;
}

void Algorithm::duplicates()
{
	int size= this->_items.size();
	for (auto it = this->_propertyKey.begin(); it != this->_propertyKey.end(); it++)
	{
		if (it->second != size)
		{
			return;
		}
	}
	throw std::exception();
}

std::string Algorithm::getQuestion()
{
	if (this->_propertyKey.empty())
	{
		std::cout << "there isnt any properties";
		throw std::exception::exception("there isnt any properties");
	}
	double target = this->_items.size() / 2.0;
	double tempValue = std::abs(target - this->_propertyKey.begin()->second);
	std::pair<std::string, int> closest = { this->_propertyKey.begin()->first,tempValue };
	//map node is in pairs so every it is a pair
	for (auto it = this->_propertyKey.begin(); it != this->_propertyKey.end(); it++)
	{
		tempValue = std::abs(target - (it->second));
		if (closest.second > tempValue)
		{
			closest = *it;
			closest.second = tempValue;
		}
	}
	return closest.first;
}

void Algorithm::selection(bool present, std::string property)
{
	for (int i = 0; i != this->_items.size(); i++)
	{
		if (this->_items[i]->search(property) != present)
		{
			Item* item = this->_items[i];
			for (int j = 0; j < item->getProperties().size(); j++)
			{
				this->_propertyKey[item->getProperties()[j]]--;
				if (this->_propertyKey[item->getProperties()[j]] == 0)
				{
					this->_propertyKey.erase(item->getProperties()[j]);
				}
			}
			this->_items.erase(this->_items.begin()+i);
			//offset
			i--;
		}
	}
}

