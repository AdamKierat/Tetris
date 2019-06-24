#ifndef FIELD_H
#define FIELD_H
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
	//Kiedy blok spada na dol, tworzy klon w tablicy field
	
	void update(Block *block);

	bool isOnBlock(Block *block);
	//Sprawdza czy block nie dotknal innego z dolu

	bool isOnLeft(Block *block);
	//Sprawdza czy block nie dotknal innego z lewej

	bool isOnRight(Block *block);
	//Sprawdza czy block nie dotknal innego z prawej

	char** getField();
	//zwraca background

	int checkLines(vector<Block*> &blocks);
	//Sprawdza czy lines sa pelne i przesuwa o jedna jedostke w dol

	bool isOver();
	//Sprawdzanie czy gra sie zakonczyla

private:
	char field[20][10];
};
#endif
