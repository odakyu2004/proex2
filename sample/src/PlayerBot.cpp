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

	
	//while(1){
		if((dungeon->getTiles()+1)==0x0){
			
			rtv = true;
			//break;
		}
		int a =0;
		cout << dungeon->getTile(a) << endl;
	//}
	
	return rtv;
}

void PlayerBot::saveAnswer(void )
{
	ofstream ofs("answer.txt");
	ofs << answer;

	return;
}
