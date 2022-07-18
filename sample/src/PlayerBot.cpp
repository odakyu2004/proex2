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
	this->setCount(0);
	this->setBefore(0);
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
	if(getBefore()!=0){
		if(getCount()<=getBefore()){
			findGoal2(dungeon);
		}
	}
	
	answer=anstmp;
	rtv=true;
	
	return rtv;
}

void PlayerBot::findGoal2(Dungeon * dungeon)
{
	vector<int> tmpanswer;

	do{
			int current = dungeon->que.front();
			if(dungeon->getTile(current)->getNorth()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					dungeon->getTile(current)->setVisit(this->getCurrentLocation());
					cout << "N" << endl;
					anstmp+="N";
					tmpanswer.push_back(current);
					current-=dungeon->width;
				}
			} else if(dungeon->getTile(current)->getEast()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					dungeon->getTile(current)->setVisit(this->getCurrentLocation());
					cout << "E" << endl;
					anstmp+="E";
					tmpanswer.push_back(current);
					current +=1;
				}
			}else if(dungeon->getTile(current)->getSouth()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					dungeon->getTile(current)->setVisit(this->getCurrentLocation());
					cout << "S" << endl;
					anstmp+="S";
					tmpanswer.push_back(current);
					current+=dungeon->width;
				}
			}else if(dungeon->getTile(current)->getWest()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					dungeon->getTile(current)->setVisit(this->getCurrentLocation());
					cout << "W" << endl;
					anstmp+="W";
					tmpanswer.push_back(current);
					current -=1;
				}
			}else if(dungeon->getTile(current)->getWarp()!= nullptr ){
				if(dungeon->getTile(current)->getVisit()==nullptr){
					dungeon->getTile(current)->setVisit(this->getCurrentLocation());
					cout << "Warp" << endl;
					tmpanswer.push_back(current);
				}
			}
			count++;
			cout << dungeon->que.front() << endl;
			dungeon->que.pop();
	}while(dungeon->que.empty() ==false);
	anstmp+="\n";
}

void PlayerBot::saveAnswer(void )
{
	
	ofstream ofs("answer.txt");
	ofs << answer;

	return;
}
