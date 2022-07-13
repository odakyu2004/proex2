/* Dungeon.cpp
 *
 * Copyright (C), 2022, x-suzuki
 */

#include "Dungeon.h"
#include "Tile.h"
#include <iostream>
#include <fstream> // ファイル入出力用のヘッダ
//#include <string>

using namespace std;

struct room {
	int south;
	int east;
	int warp;
};

template<typename CharT, typename Traits>
std::basic_ifstream<CharT,Traits>&
operator>>(std::basic_ifstream<CharT,Traits>& is, room& pt) {
	is >> pt.south >> pt.east >> pt.warp;
	return is;
}

Dungeon::Dungeon() {

}

Dungeon::~Dungeon() {
	for(unsigned int i=0; i<tiles.size(); i++) {
		delete tiles[i];
	}
}

/**
 * @fn Dungeon::loadData(void )
 *  データを読み込んで迷宮を再生する
 * @brief 読み込んだデータを一時的に保存し、vectorで数を作った後、一時データから一気に接続状況を作る
 */
void Dungeon::loadData(void )
{
	ifstream ifs("data.txt");
	int width;  // 東西方向の部屋の個数
	int length; // 南北方向の部屋の個数
	ifs >> width; // 東西方向の部屋の個数を読み込む
	ifs >> length; // 南北方向の部屋の個数を読み込む
	unsigned int size(width * length); //unsigned int型のsizeという変数を宣言し部屋数の総数を代入している
	cout << size << endl; //部屋の数を表示
	this->sizet = size;
	// ここから部屋のデータの保存 N,S,W,E,warpID
	room data[size];//room構造体の配列宣言

	for(unsigned int i=0; i<size; i++) { //ループで１行ずつデータを配列に保存
		ifs >> data[i]; // 2行目以降,部屋の接続状況が保存されているので一時的にdataへ
		tiles.push_back(new Tile); //Tile.hで宣言されているTile *をtilesというvectorで宣言してあるので、そこにpush_backでTileを代入している
	}
	for(unsigned int i=0; i<size; i++) {
		// 左上から右に移動
		// 南と東の壁の接続状況がわかれば、北と西も自動的にわかる
		// 一方通行はなしと考える
		if (data[i].south == 1) { //もし南側が通路だったら
			tiles[i]->setSouth(tiles[i+width]); //一個したの行の部屋なので横幅分足せば１行下に行く
			tiles[i+width]->setNorth(tiles[i]); //
		}
		if (data[i].east == 1) { //もし東側が通路だったら
			tiles[i]->setEast(tiles[i+1]); //西から来たので東の部屋は一個隣なのでプラス1する
			tiles[i+1]->setWest(tiles[i]); //
		}
		if (data[i].warp != -1) {
			tiles[i]->setWarp(tiles[data[i].warp]);
		}
		
		cout << "[" << i << "]" << endl;
		cout << "east" << data[i].east << endl;
		cout << "south" << data[i].south << endl;
		cout << "warp" << data[i].warp << endl;
		cout << "nouth" << tiles[i+width] << endl;
		cout << "west" << tiles[i+1] << endl;
	}
	return;
}
