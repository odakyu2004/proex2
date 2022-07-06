/* main.cpp
 *
 * Copyright (C), 2022, x-suzuki
 */
#include <iostream>
#include "Tile.h"
#include "Dungeon.h"
#include "PlayerBot.h"

using namespace std;

int run00(void );
int run01(void );
int run02(void );
int run03(void );

int main()
{
	return run03();
}

int run03(void)
{
	Dungeon d1;

	d1.loadData();

	PlayerBot bot;
	bot.findGoal(&d1);
	bot.saveAnswer();

	return 0;
}