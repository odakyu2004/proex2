/* main.cpp
 *
 * Copyright (C), 2022, x-suzuki
 */
#include <iostream>
#include "Tile.h"
#include "Dungeon.h"
#include "PlayerBot.h"

using namespace std;

int run03(void );

int main()
{
	Dungeon d1;
	d1.loadData();
	
	PlayerBot bot;
	bot.findGoal(&d1);
	cout << "OK2" << endl;
	bot.saveAnswer();

	return 0;
}