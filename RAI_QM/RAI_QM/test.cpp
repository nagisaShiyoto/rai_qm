#include "Helper.h"
#include "FileHelper.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include "Algorithm.h"
#include "saveDataBase.h"
int main()
{
	std::string answer = "";
	Algorithm test("../exemples/empty.txt");
	bool con = true;
	while (con)
	{
		test.playGame();
		answer=Helper::getAnswersFromUser("do you want to play again? (t/f)");
		con = Helper::toBool(answer);
		test.setItems(saveDataBase::_allItems);
		test.setPropertyKey(saveDataBase::_allProperties);
	}
		
	return 0;
}