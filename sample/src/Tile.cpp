/* Tile.cpp
 *
 * Copyright (C), 2022, x-suzuki
 */

#include "Tile.h"
#include "PlayerBot.h"

Tile::Tile() {
	this->setNorth(nullptr);
	this->setSouth(nullptr);
	this->setEast(nullptr);
	this->setWest(nullptr);
	this->setWarp(nullptr);
	//this->setCheck(nullptr);
	this->setPlayerBot(nullptr);
}

Tile::~Tile() {

}

//一度探索したか判定
