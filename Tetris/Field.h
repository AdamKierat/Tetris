#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>
#include "Block.h"
using namespace std;

class Block;
class Field
{
public:
	Field();
	void display();
	//When the block falls down, put his clone in field table
	
	void update(Block *block);

	bool isOnBlock(Block *block);
	//Check if block touch another from bottom

	bool isOnLeft(Block *block);
	//Check if block touch another from left

	bool isOnRight(Block *block);
	//Check if block touch another from right

	char** getField();
	//Return background/map

	int checkLines(vector<Block*> &blocks);
	//Check if lines are full and move one unit down, if lines clear

	bool isOver();
	//Check if is game over

private:
	char field[20][10];
};

