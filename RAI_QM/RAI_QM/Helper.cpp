#include "Helper.h"

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
