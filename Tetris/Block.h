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
	void move(float set_X, float set_Y);

	bool isOnLeft(RenderWindow &window);
	bool isOnRight(RenderWindow &window);
	bool isBottom(RenderWindow &window);

	Vector2f* getPosition();

	void drawBlock(RenderWindow &window, Field field);

	void moveBlock(Field F, int row);
	
	virtual void rotatePiece(Field F) = 0;

protected:
	RectangleShape blocks[4];

	Texture titleTexture;

	int BRCIK_SIZE;
	int angle;

private:
	void draw(RenderTarget &target, RenderStates states)const;
};

