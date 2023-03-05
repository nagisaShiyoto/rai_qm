#pragma once
#include <iostream>
#include <vector>
class Helper
{
public:
	static std::vector<std::string> split(std::string splitPlace,std::string str);
	static std::string join(std::string addString, std::vector<std::string> vec);
	static std::string getAnswersFromUser(std::string question);
	static bool toBool(std::string answer);
    static void set_console_color(unsigned int color);
};