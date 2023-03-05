#include <Windows.h>
#include "Helper.h"
#include <string>
std::vector<std::string> Helper::split(std::string splitPlace, std::string str)
{
    std::vector<std::string> splitedstr;
    size_t place = 0;
    while ((place=str.find(splitPlace)) != std::string::npos)
    {

        splitedstr.push_back(str.substr(0, place));
        str = str.substr(place+splitPlace.length());
    }
    splitedstr.push_back(str.substr(0));
    return splitedstr;
}

std::string Helper::join(std::string addString, std::vector<std::string> vec)
{
    std::string line = "";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        line+= *it+addString;
    }
    line = line.substr(0, line.length() - 1);
    return line;
}

std::string Helper::getAnswersFromUser(std::string question)
{
    std::string answer = "";
    do
    {
        std::cout << question << std::endl;
        std::getline(std::cin, answer);
    } while (answer != "t" && answer != "f" && answer != "true" && answer != "false");
    return answer;
}

bool Helper::toBool(std::string answer)
{
    if (answer == "t" || answer == "true")
    {
        return true;
    }
    if (answer == "f" || answer == "false")
    {
        return false;
    }
    std::cout << "cant convert to bool";
    throw std::exception("cant convert to bool");
}

void Helper::set_console_color(unsigned int color)
{
    // colors are 0=black 1=blue 2=green and so on to 15=white
    // colorattribute = foreground + background * 16
    // to get red text on yellow use 4 + 1416 = 228
    // light red on yellow would be 12 + 1416 = 236
    // a Dev-C++ tested console application by vegaseat 07nov2004

    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
