#include "OBlock.h"

OBlock::OBlock() {
	tileTexture.loadFromFile("images/ob.png");
	BRICK_SIZE = 30;
	angle = 0;

	// Laduje tekstury klocka
	for (int i = 0; i < 4; i++) {
		blocks[i].setSize(Vector2f(BRICK_SIZE, BRICK_SIZE));
		blocks[i].setTexture(&tileTexture);
	}

	// Ustawiam ksztalt klocka "O"
	blocks[0].setPosition(Vector2f(4 * BRICK_SIZE, -BRICK_SIZE));
	blocks[1].setPosition(Vector2f(5 * BRICK_SIZE, -BRICK_SIZE));
	blocks[2].setPosition(Vector2f(4 * BRICK_SIZE, 0));
	blocks[3].setPosition(Vector2f(5 * BRICK_SIZE, 0));
}

void OBlock::rotateBlock(Field f) {
	return;
}
