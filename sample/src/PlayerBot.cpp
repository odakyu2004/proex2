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
	/* 4 方向への隣接頂点への移動を表すベクトル */
	const int dx[5] = { 0,1,2,3,4};
	int next=0;
	bool rtv(false);
	vector<int> dist(dungeon->getSize(), -1); 
	dist[0] = 0;
	vector<int> prev(dungeon->getSize(), -1);
	queue<int> que;
	que.push(0);
	
	while(!que.empty()){
		int current_pos = que.front(); 
	    int x = current_pos;
		que.pop();
		
		for (int direction = 0; direction < 4; ++direction) {
			if(dx[direction]==0 ){
				if(dungeon->getTile(x)->getNorth()!= nullptr ){
					next=x-dungeon->length;
					cout << "N" << endl;
				}
			}
			if(dx[direction]==1 ){
				if(dungeon->getTile(x)->getEast()!= nullptr ){
					next=x+1;
					cout << "E" << endl;
				}
			}
			if(dx[direction]==2 ){
				if(dungeon->getTile(x)->getSouth()!= nullptr ){
					next=x+dungeon->length;
					cout << "S" << endl;
				}
			}
			if(dx[direction]==3 ){
				if(dungeon->getTile(x)->getWest()!= nullptr ){
					next=x-1;
					cout << "W" << endl;
				}
			}
			if(dx[direction]==4 ){
				if(dungeon->getTile(x)->getWarp()== nullptr ){
					//none
				}
			}
			
			if(dist[next]==-1){
				que.push(next);
				dungeon->getTile(next)->setVisit(dungeon->getTile(x));
				dist[next] = dist[x] + 1;
				prev[next] = x;
			}
		}
		
		if(x==dungeon->getSize()-1){
			break;
		}
		
	}
	/*for(unsigned int i=0;i<dungeon->getSize();i++){
		cout << prev[i] << endl;
	}*/
	rtv=true;
	
	return rtv;
}


void PlayerBot::saveAnswer(void )
{
	
	ofstream ofs("answer.txt");
	ofs << answer;

	return;
}

