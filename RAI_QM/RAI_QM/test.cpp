#include "Helper.h"
#include "FileHelper.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include "Algorithm.h"
int main()
{
	Algorithm test("../exemples/empty.txt");
	test.playGame();
	return 0;
}