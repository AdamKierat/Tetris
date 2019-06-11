#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
#include <iostream>
#include <cstdlib>
using namespace sf;
using namespace std;


class Block: public Drawable , public Transformable
{
public:
	// method of moving block
	void move(float set_X, float set_Y);
	// Three methods checking if blocks are on the edge
	bool isOnLeft(RenderWindow &window);
	bool isOnRight(RenderWindow &window);
	bool isOnBottom(RenderWindow &window);
	//return 4 directions of block possition
	Vector2f* getPosition();

	//Draws block if blocks is in field table
	void drawBlock(RenderWindow &window, Field field);

	//Moves block down if block is in field table
	//Method will only works if element of block will fits inside row
	void moveBlock(Field F, int row);
	
	virtual void rotateBlock(Field F) = 0;
	// for inherited classes 

protected:
	RectangleShape blocks[4];
	int BRICK_SIZE;
	Texture tileTexture;

	
	int angle;

private:
	void draw(RenderTarget &target, RenderStates states)const;
};
