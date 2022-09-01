//* PlayerBot.cpp
 *
 * Copyright (C), 2022, x-suzuki
 */

#include "PlayerBot.h"
#include "Tile.h"
#include "Dungeon.h"
#include <fstream>
#include <stack>


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
bool PlayerBot::findGoal(Dungeon * map)
{
	int size = map->getWidth()*map->getLength();
	bool rtv(false);
	int n = 0;
	int i = 0;

	struct Re{
		int dis;
		string dir;
	};
	struct Re re[size];

	int num =0;
	int count =0;
	queue<int > out;
	stack<int > st;
	que.push(0);
	
	while(!que.empty() && map->getTile(count)->getGoal()==nullptr){
		next = que.front();
		que.pop();

		for(n=0;n<4;n++){
			if(n==0){
				if(map->getTile(next)->getNorth()!=nullptr && map->getTile(next-map->getWidth())->getVisit()==nullptr){
					que.push(next-map->getWidth());
					cout << "N" << endl;
					st.push(count);
					re[num].dis = count;
					re[num].dir = "S";
					num++;
					map->getTile(next)->setVisit(map->getTile(next));
				}
			}
			if(n==1){
				if(map->getTile(next)->getEast()!=nullptr && map->getTile(next+1)->getVisit()==nullptr){
					que.push(next+1);
					cout << "E" << endl;
					st.push(count);
					re[num].dis = count;
					re[num].dir = "W";
					num++;
					map->getTile(next)->setVisit(map->getTile(next));
				}
			}
			if(n==2){
				if(map->getTile(next)->getSouth()!=nullptr && map->getTile(next+map->getWidth())->getVisit()==nullptr){
					que.push(next+map->getWidth());
					cout << "S" << endl;
					st.push(count);
					re[num].dis = count;
					re[num].dir = "N";
					num++;
					map->getTile(next)->setVisit(map->getTile(next));
				}
			}
			if(n==3){
				if(map->getTile(next)->getWest()!=nullptr && map->getTile(next-1)->getVisit()==nullptr){
					que.push(next-1);
					cout << "W" << endl;
					st.push(count);
					re[num].dis = count;
					re[num].dir = "E";
					num++;
					map->getTile(next)->setVisit(map->getTile(next));
				}
			}
			if(n==4){		
				if(map->getTile(next)->getWarp()!=nullptr && map->getTile(next)->getWarp()->getVisit()==nullptr){
					//SwitchFunc(map);
				}
			}	
		}
		count++;
	}
	int cNum = 0;
	int before = size*size;
	cout << "--------" << endl;
	do{
		cNum = st.top();
		st.pop();
		if(cNum != before){
			if(cNum < before){
				cout << "--------" << endl;
				cout << re[num-i].dir << endl;
				answer+=re[num-i].dir;
				before = cNum;
			}
		}
		i++;
	}while(!st.empty());
	cout << re[0].dir << endl;
	answer+= re[0].dir;
	rtv = true;
	return rtv;
}

/*int PlayerBot::SwitchFunc(Dungeon * map){
	for(int n=0;n<3;n++){
		switch(n){
			case 0: 
				if(map->getTile(next)->getWarp()->getNorth()!=nullptr && map->getTile(next-map->getWidth())->getVisit()==nullptr){
					que.push(next-map->getWidth());
				}
				break;
			case 1:
				if(map->getTile(next)->getWarp()->getEast()!=nullptr && map->getTile(next+1)->getVisit()==nullptr){
					que.push(next+1);
				}
				break;
			case 2:
				if(map->getTile(next)->getWarp()->getSouth()!=nullptr && map->getTile(next+map->getWidth())->getVisit()==nullptr){
					que.push(next+map->getWidth());
				}
				break;
			case 3:
				if(map->getTile(next)->getWarp()->getWest()!=nullptr && map->getTile(next-1)->getVisit()==nullptr){
					que.push(next-1);
				}
				break;
		}
	}
}*/

void PlayerBot::saveAnswer(void )
{
	ofstream ofs("answer.txt");
	ofs << answer;

	return;
}
