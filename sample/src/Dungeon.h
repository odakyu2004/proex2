#ifndef _SRC_DUNGEON_H_
#define _SRC_DUNGEON_H_

#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Tile;

class Dungeon {
private:
	vector<Tile *> tiles;
public:
	Dungeon();
	virtual ~Dungeon();
	int width;  // 東西方向の部屋の個数
	int length; // 南北方向の部屋の個数
	void loadData(void );
	void setWidth(int width){this->width = width;}
	int getWidth(void) {return width;}
	int getSize(void){ return width*length;}
	int X;
	int Y;

	vector<Tile *> * getTiles(void ) { return & tiles; }
	Tile * getTile(int number) { return tiles[number]; }//引数に欲しい部屋の番号を入れたらその部屋の状況を返す
};

#endif /* _SRC_DUNGEON_H_ */