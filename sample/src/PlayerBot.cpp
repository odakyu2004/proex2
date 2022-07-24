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
	int next_x =0, next_y =0;
	bool rtv(false);
	vector<vector<int> > dist(dungeon->length, vector<int>(dungeon->width, -1)); 
	dist[0][0] = 0;
	vector<vector<int> > prev_x(dungeon->length, vector<int>(dungeon->width, -1));
    vector<vector<int> > prev_y(dungeon->length, vector<int>(dungeon->width, -1));
	queue<pair<int, int> > que;
	que.push(make_pair(0, 0));
	while(!que.empty()){
		pair<int, int> current_pos = que.front(); 
	    int x = current_pos.first;
        int y = current_pos.second;
		que.pop();

		for (int direction = 0; direction < 5; ++direction) {
			if(dx[direction]==0 ){
				if(dungeon->getTile(x,y)->getNorth()!= nullptr ){
					next_y=(y-1);
				}
			}
			if(dx[direction]==1 ){
				if(dungeon->getTile(x,y)->getEast()!= nullptr ){
					next_x=(x+1);
				}
			}
			if(dx[direction]==2 ){
				if(dungeon->getTile(x,y)->getSouth()!= nullptr ){
					next_y=(y+1);
				}
			}
			if(dx[direction]==3 ){
				if(dungeon->getTile(x,y)->getWest()== nullptr ){
					next_x=(x-1);
				}
			}
			if(dx[direction]==4 ){
				if(dungeon->getTile(x,y)->getWarp()== nullptr ){
					//none
				}
			}

			if(dungeon->getTile(next_x,next_y)->getVisit()==nullptr){
				que.push(make_pair(next_x, next_y));
				dungeon->getTile(next_x,next_y)->setVisit(dungeon->getTile(x,y));
				dist[next_x][next_y] = dist[x][y] + 1;
				prev_x[next_x][next_y] = x;
                prev_y[next_x][next_y] = y;
			}
		}
		if(((x+1)*(y+1))==((dungeon->length)*(dungeon->width))){
			break;
		}
	}

	rtv=true;
	
	return rtv;
}


void PlayerBot::saveAnswer(void )
{
	
	ofstream ofs("answer.txt");
	ofs << answer;

	return;
}
