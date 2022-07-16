/* Dungeon.h
 *
 * Copyright (C), 2022, x-suzuki
 */

#ifndef _SRC_DUNGEON_H_
#define _SRC_DUNGEON_H_

#include <vector>
#include <queue>

using namespace std;

class Tile;

class Dungeon {
private:
	vector<Tile *> tiles;
public:
	Dungeon();
	virtual ~Dungeon();
	void loadData(void );
	queue<int> que;
	vector<Tile *> * getTiles(void ) { return & tiles; }
	Tile * getTile(int number) { return tiles[number]; }//引数に欲しい部屋の番号を入れたらその部屋の状況を返す
};

#endif /* _SRC_DUNGEON_H_ */