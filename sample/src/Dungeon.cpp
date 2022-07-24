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
	for(unsigned int i=0; i<length; i++) {
		for(unsigned int j=0; j<width; j++) {
			delete tiles[i][j];
		}
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
	
	ifs >> width; // 東西方向の部屋の個数を読み込む
	ifs >> length; // 南北方向の部屋の個数を読み込む
	unsigned int size(width * length); //unsigned int型のsizeという変数を宣言し部屋数の総数を代入している
	cout << size << endl; //部屋の数を表示
	// ここから部屋のデータの保存 N,S,W,E,warpID
	room data[width][length];//room構造体の配列宣言
	
	for(unsigned int i=0; i<length; i++) { //ループで１行ずつデータを配列に保存
		for(unsigned int j=0; j<width; j++) { 
			ifs >> data[i][j]; 
			tiles[0].push_back(new Tile);
		}
	}
	
	for(unsigned int i=0; i<length; i++) {
		for(unsigned int j=0; j<width; j++) { 
			if (data[i][j].south == 1) { //もし南側が通路だったら
				tiles[i][j]->setSouth(tiles[i+width][j]); //一個したの行の部屋なので横幅分足せば１行下に行く
				tiles[i+width][j]->setNorth(tiles[i][j]); //
			}
			if (data[i][j].east == 1) { //もし東側が通路だったら
				tiles[i][j]->setEast(tiles[i+1][j]); //西から来たので東の部屋は一個隣なのでプラス1する
				tiles[i+1][j]->setWest(tiles[i][j]); //
			}
			if (data[i][j].warp != -1) {
				unsigned int Xw=0,Yw=0;
				Yw=(data[i][j].warp)/length;
				Xw=(data[i][j].warp)-(width*Yw);
				tiles[i][j]->setWarp(tiles[Xw][Yw]);
			}
		}
	}
	return;
}
