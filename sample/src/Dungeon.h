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
	vector<vector<Tile *> > tiles;
public:
	Dungeon();
	virtual ~Dungeon();
	int width;  // 東西方向の部屋の個数
	int length; // 南北方向の部屋の個数
	int X;
	int Y;
	void loadData(void );
	vector<vector <Tile *> > * getTiles(void ) { return & tiles; }
	Tile * getTile(int X,int Y) { return tiles[X][Y]; }//引数に欲しい部屋の番号を入れたらその部屋の状況を返す
};

#endif /* _SRC_DUNGEON_H_ */