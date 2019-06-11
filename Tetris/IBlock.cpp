#include "IBlock.h"

IBlock::IBlock() {
	tileTexture.loadFromFile("images/brick.png");
	BRICK_SIZE = 30;
	angle = 0;

	// Laduje tekstury klocka
	for (int i = 0; i < 4; i++) {
		blocks[i].setSize(Vector2f(BRICK_SIZE, BRICK_SIZE));
		blocks[i].setTexture(&tileTexture);
	}

	// Ustawiam ksztalt klocka "I"
	blocks[0].setPosition(Vector2f(3 * BRICK_SIZE, 0));
	blocks[1].setPosition(Vector2f(4 * BRICK_SIZE, 0));
	blocks[2].setPosition(Vector2f(5 * BRICK_SIZE, 0));
	blocks[3].setPosition(Vector2f(6 * BRICK_SIZE, 0));
}
	void IBlock::rotateBlock(Field f) {
	Vector2f position, positionR;
	char** fieldP = f.getField();

	char field[20][10];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = fieldP[i][j];
		}
	}

	for (int i = 0; i < 20; i++) {
		delete[] fieldP[i];
	}
	delete[] fieldP;

	int x, y;

	switch (angle) {
	case 0:
		// Sprawdzam czy moge obrocic
		positionR = blocks[2].getPosition();
		y = positionR.x / 30;
		x = positionR.y / 30;

		if (field[x - 1][y] == 'x' || field[x + 1][y] == 'x' || field[x + 2][y] == 'x') return;

		position = blocks[1].getPosition();

		// Jesli wyszedlem za ekran, ale nie moge obrocic
		if (position.y == 540 && field[x - 2][y] == 'x') return;
		if (position.y == 570 && (field[x - 2][y] == 'x' || field[x - 3][y] == 'x')) return;

		blocks[0].move(2 * BRICK_SIZE, 2 * BRICK_SIZE);
		blocks[1].move(BRICK_SIZE, BRICK_SIZE);
		blocks[3].move(-BRICK_SIZE, -BRICK_SIZE);

		// Jesli przy obracaniu wyszedlem za ekran
		if (position.y == 540) this->move(0, -30);
		if (position.y == 570) this->move(0, -60);
		angle++;
		break;

	case 1:
		// Sprawdzam czy moge obrocic
		positionR = blocks[2].getPosition();
		y = positionR.x / 30;
		x = positionR.y / 30;

		if (field[x][y - 1] == 'x' || field[x][y - 2] == 'x' || field[x][y + 1] == 'x') return;

		position = blocks[1].getPosition();

		// Jesli wyszedlem za ekran, ale nie moge obrocic

		if (position.x == 270 && field[x][y - 3] == 'x') return;
		if (position.x == 0 && (field[x][y + 3] == 'x' || field[x][y + 4] == 'x')) return;
		if (position.x == 30 && field[x][y + 2] == 'x') return;

		blocks[0].move(-2 * BRICK_SIZE, -2 * BRICK_SIZE);
		blocks[1].move(-BRICK_SIZE, -BRICK_SIZE);
		blocks[3].move(BRICK_SIZE, BRICK_SIZE);

		// Jesli przy obracaniu wyszedlem za ekran
		if (position.x == 270) this->move(-30, 0);
		if (position.x == 0) this->move(60, 0);
		if (position.x == 30)   this->move(30, 0);
		angle = 0;
		break;

	}
}

