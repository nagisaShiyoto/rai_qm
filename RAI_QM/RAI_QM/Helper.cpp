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
        std::cin >> answer;
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
