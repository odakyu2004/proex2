/* PlayerBot.h
 *
 * Copyright (C), 2022, x-suzuki
 */

#ifndef _SRC_PLAYERBOT_H_
#define _SRC_PLAYERBOT_H_
#include <string>

using namespace std;

class Tile;
class Dungeon;

class PlayerBot {
private:
	string answer;
	string anstmp;
	Tile * currentLocation;
	int count;
	int before;
public:
	PlayerBot();
	virtual ~PlayerBot();
	string * getAnswer(void ) { return & answer; }
	void setCurrentLocation(Tile * tile) { this->currentLocation = tile; }
	Tile * getCurrentLocation(void ) { return currentLocation; }
	void setCount(int count){this->count = count;}
	int getCount(void) {return count;}
	void setBefore(int count){this->before = before;}
	int getBefore(void) {return before;}

	bool findGoal(Dungeon * dungeon);
	void findGoal2(Dungeon * dungeon);
	void saveAnswer(void );
};

#endif /* _SRC_PLAYERBOT_H_ */
