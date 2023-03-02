#include "Helper.h"
#include <iostream>
#include <vector>
int main()
{
	std::vector<std::string> test = Helper::split(" ", "cat dog mouse");
	test= Helper::split(",", "cat,dog mouse");
	test = Helper::split("-split-", "cat-split-dog-split-mouse");
}