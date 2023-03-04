#pragma once
#include <iostream>
#include <map>
#include<vector>
#include<string>
#include "Item.h"
#include "Helper.h"
#include "FileHelper.h"
class Algorithm
{
public:
	Algorithm(std::string filePath);
	void playGame();
	~Algorithm();
private:
	std::string getQuestion();
	//it suppose to be has but we need it fancy:)
	void selection(bool present, std::string property);
	std::string _filePath;
	std::map<std::string, int> _propertyKey;
	std::vector <Item*> _items;
};
