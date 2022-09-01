/* Dungeon.h
 *
 * Copyright (C), 2022, x-suzuki
 */

#ifndef _SRC_DUNGEON_H_
#define _SRC_DUNGEON_H_

#include <vector>

using namespace std;

class Tile;

class Dungeon {
private:
	vector<Tile *> tiles;
public:
	Dungeon();
	virtual ~Dungeon();
	void loadData(void );
	vector<Tile *> * getTiles(void ) { return & tiles; }
	Tile * getTile(int number) { return tiles[number]; }
};

#endif /* _SRC_DUNGEON_H_ */
