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
	int p =0;
	int next=0;
	int i =0;
	bool rtv(false);

	stack<int > prev;
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
					
					if(dungeon->getTile(next)->getVisit()== nullptr ){
						cout << "N" << endl;
						que.push(next);
						prev.push(next);
						dungeon->getTile(x)->setVisit(dungeon->getTile(next));
						dungeon->getTile(next)->setVisit(dungeon->getTile(x));
					}else {
						next=x+dungeon->length;
					}
				}
			}
			if(dx[direction]==1 ){
				if(dungeon->getTile(x)->getEast()!= nullptr ){
					next=x+1;
					if(dungeon->getTile(next)->getVisit()== nullptr ){
						cout << "E" << endl;
						que.push(next);
						prev.push(next);
						dungeon->getTile(x)->setVisit(dungeon->getTile(next));
						dungeon->getTile(next)->setVisit(dungeon->getTile(x));
					}else {
						next=x-1;
					}
				}
			}
			
			if(dx[direction]==2 ){
				if(dungeon->getTile(x)->getSouth()!= nullptr ){
					next=x+dungeon->length;
					if(dungeon->getTile(next)->getVisit()== nullptr ){
						cout << "S" << endl;
						que.push(next);
						prev.push(next);
						dungeon->getTile(x)->setVisit(dungeon->getTile(next));
						dungeon->getTile(next)->setVisit(dungeon->getTile(x));
					}else {
						next=x-dungeon->length;
					}
				}
			}
			if(dx[direction]==3 ){
				if(dungeon->getTile(x)->getWest()!= nullptr ){
					next=x-1;
					if(dungeon->getTile(next)->getVisit()== nullptr ){
						cout << "W" << endl;
						que.push(next);
						prev.push(next);
						dungeon->getTile(x)->setVisit(dungeon->getTile(next));
						dungeon->getTile(next)->setVisit(dungeon->getTile(x));
					}else {
						next=x+1;
					}
				}
			}
			if(dx[direction]==4 ){
				if(dungeon->getTile(x)->getWarp()== nullptr ){
					//none
				}
			}
			
		}
		if(x==dungeon->getSize()){
			cout << "---" << endl;
			break;
		}
		
	}


	for(i=0;i!=dungeon->getSize()-1;i++){
		p = prev.top();
		prev.pop();
		
		if(dungeon->getTile(p)->getNorth()!= nullptr ){
			if(dungeon->getTile(p-dungeon->length)->getVisit2()== nullptr ){
				cout << "N" << endl;
				dungeon->getTile(p)->setVisit2(dungeon->getTile(p-dungeon->length));
				dungeon->getTile(p-dungeon->length)->setVisit2(dungeon->getTile(p));
			}
		}else if(dungeon->getTile(p)->getEast()!= nullptr ){
			if(dungeon->getTile(p+1)->getVisit2()== nullptr ){
				cout << "E" << endl;
				dungeon->getTile(p)->setVisit2(dungeon->getTile(p+1));
				dungeon->getTile(p+1)->setVisit2(dungeon->getTile(p));
			}
		}else if(dungeon->getTile(p)->getSouth()!= nullptr ){
			if(dungeon->getTile(p+dungeon->length)->getVisit2()== nullptr ){
				cout << "S" << endl;
				dungeon->getTile(p)->setVisit2(dungeon->getTile(p+dungeon->length));
				dungeon->getTile(p+dungeon->length)->setVisit2(dungeon->getTile(p));
			}
		}else if(dungeon->getTile(p)->getWest()!= nullptr ){
			if(dungeon->getTile(p-1)->getVisit2()== nullptr ){
				cout << "W" << endl;
				dungeon->getTile(p)->setVisit2(dungeon->getTile(p-1));
				dungeon->getTile(p-1)->setVisit2(dungeon->getTile(p));
			}
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