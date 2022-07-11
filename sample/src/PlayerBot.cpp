/* PlayerBot.cpp
 *
 * Copyright (C), 2022, x-suzuki
 */

#include "PlayerBot.h"
#include "Tile.h"
#include "Dungeon.h"
#include <fstream>
#include <iostream>


using namespace std;

PlayerBot::PlayerBot(void ) {
	this->setCurrentLocation(nullptr);
}

PlayerBot::~PlayerBot() {

}

/**
 * @fn PlayerBot::findGoal(Dungeon * dungeon)
 * ダンジョンのゴールまでの行き方を探す.
 *
 */
bool PlayerBot::findGoal(Dungeon * dungeon)
{
	bool rtv(false);

	if(dungeon->getTiles()==0x0){
		cout << "hogehoge" << endl;
	answer = "n";
	answer += "n";
	answer += "w";
	answer += "w";
	rtv = true;
	}
	return rtv;
}

void PlayerBot::saveAnswer(void )
{
	ofstream ofs("answer.txt");
	ofs << answer;

	return;
}
