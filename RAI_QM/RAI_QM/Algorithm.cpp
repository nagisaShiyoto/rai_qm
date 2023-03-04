#include "Algorithm.h"
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
}

void Algorithm::playGame()
{
	std::string property = "";
	std::string answer = "";
	while (this->_items.size() > 1)
	{
		property = this->getQuestion();
		answer = Helper::getAnswersFromUser("is it " + property + " (t/f)");
		this->selection(Helper::toBool(answer), property);
	}
	if (this->_items.size() == 0)
	{
		std::cout << "coudnt find item";
		throw std::exception();
	}
	else
	{
		std::cout << "is it: " << this->_items[0]->getName()<<"?"<<std::endl;
	}
}

Algorithm::~Algorithm()
{
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

