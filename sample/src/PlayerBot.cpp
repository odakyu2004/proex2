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
	int count = 0;
	
		do{
			int current = dungeon->que.front();
			if(dungeon->getTile(current)->getNorth()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					cout << "N" << endl;
					tmpanswer += 'N';
				}
			} else if(dungeon->getTile(current)->getEast()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					cout << "E" << endl;
					tmpanswer += 'E';
				}
			}else if(dungeon->getTile(current)->getSouth()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					cout << "S" << endl;
					tmpanswer += 'S';
				}
			}else if(dungeon->getTile(current)->getWest()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					cout << "W" << endl;
					tmpanswer += 'W';
				}
			}else if(dungeon->getTile(current)->getWarp()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					cout << "Warp" << endl;

				}
			}
			count++;
			cout << dungeon->que.front() << endl;
			dungeon->que.pop();
		}while(dungeon->que.empty() ==false);

	
	
	rtv=true;
	
	return rtv;
}

void PlayerBot::saveAnswer(void )
{
	ofstream ofs("answer.txt");
	ofs << answer;

	return;
}
