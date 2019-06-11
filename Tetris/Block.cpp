#include "Block.h"

void Block::move(float offsetX, float offsetY) {
	for (int i = 0; i < 4; i++) {
		blocks[i].move(offsetX, offsetY);
	}
}

bool Block::isOnLeft(RenderWindow &window) {
	Vector2f position;
	for (int i = 0; i < 4; i++) {
		position = blocks[i].getPosition();
		if (position.x == 0) return true;
	}
	return false;
}

bool Block::isOnRight(RenderWindow &window) {
	Vector2f position;
	for (int i = 0; i < 4; i++) {
		position = blocks[i].getPosition();
		if (position.x == 270) return true;
	}
	return false;
}

bool Block::isOnBottom(RenderWindow &window) {
	Vector2f position;
	for (int i = 0; i < 4; i++) {
		position = blocks[i].getPosition();
		if (position.y == 570) return true;
	}
	return false;
}

Vector2f* Block::getPosition() {
	Vector2f *positions;
	positions = new Vector2f[4];
	for (int i = 0; i < 4; i++) {
		positions[i] = blocks[i].getPosition();
		positions[i].x = positions[i].x / BRICK_SIZE;
		positions[i].y = positions[i].y / BRICK_SIZE;
	}

	return positions;
}

void Block::drawBlock(RenderWindow &window, Field f) {
	Vector2f* positions;
	int x, y;
	char** fieldP = f.getField();

	char field[20][10];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = fieldP[i][j];
		}
	}

	positions = this->getPosition();

	// Sprawdzam, ktore z czterech elementow klocka pokrywaja sie z iksami, te elementy bede rysowac
	for (int i = 0; i < 4; i++) {
		x = positions[i].y;
		y = positions[i].x;
		if (field[x][y] == 'x') window.draw(this->blocks[i]);
	}

	delete[] positions;
	for (int i = 0; i < 20; i++) {
		delete[] fieldP[i];
	}
	delete[] fieldP;
}

void Block::moveBlock(Field f, int row) {
	Vector2f* positions;
	int x, y;
	char** fieldP = f.getField();

	char field[20][10];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = fieldP[i][j];
		}
	}

	positions = this->getPosition();

	for (int i = 0; i < 4; i++) {
		x = positions[i].y;
		if (x < row) {
			y = positions[i].x;
			if (field[x][y] == 'x') {
				this->blocks[i].move(0, 30);
			}
		}
	}

	delete[] positions;
	for (int i = 0; i < 20; i++) {
		delete[] fieldP[i];
	}
	delete[] fieldP;
}

void Block::draw(RenderTarget &target, RenderStates states) const {
	for (int i = 0; i < 4; i++) {
		target.draw(this->blocks[i], states);
	}
}
