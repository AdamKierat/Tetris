#include "Field.h"

Field::Field() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = '.';
		}
	}
}

void Field::display() {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}
}

void Field::update(Block *block) {
	Vector2f* positions;
	positions = block->getPosition();
	int x, y;

	for (int i = 0; i < 4; i++) {
		x = positions[i].x;
		y = positions[i].y;
		field[y][x] = 'x';
	}
	delete[] positions;
}

bool Field::isOnBlock(Block *block) {
	Vector2f* positions;
	positions = block->getPosition();
	int x, y;

	// Sprawdzam czy pod klockiem sa iksy, czyli inne klocki
	for (int i = 0; i < 4; i++) {
		x = positions[i].y;
		y = positions[i].x;
		if (field[x + 1][y] == 'x') {
			delete[] positions;
			return true;
		}
	}

	delete[] positions;
	return false;
}

bool Field::isOnLeft(Block *block) {
	Vector2f* positions;
	positions = block->getPosition();
	int x, y;

	// Sprawdzam czy na lewo od klocka sa iksy, czyli inne klocki
	for (int l = 0; l < 4; l++) {
		x = positions[l].y;
		y = positions[l].x;
		if (field[x][y - 1] == 'x') {
			delete[] positions;
			return true;
		}
	}

	delete[] positions;
	return false;
}

bool Field::isOnRight(Block *block) {
	Vector2f* positions;
	positions = block->getPosition();
	int x, y;

	// Sprawdzam czy na prawo od klocka sa iksy, czyli inne klocki
	for (int l = 0; l < 4; l++) {
		x = positions[l].y;
		y = positions[l].x;
		if (field[x][y + 1] == 'x') {
			delete[] positions;
			return true;
		}
	}

	delete[] positions;
	return false;
}

char** Field::getField() {
	char** fieldR;
	fieldR = new char*[20];
	for (int i = 0; i < 20; i++) {
		fieldR[i] = new char[10];
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			fieldR[i][j] = field[i][j];
		}
	}

	return fieldR;
}

int Field::checkLines(vector<Block*> &blocks) {
	int counter, deleted = 0;

	for (int i = 0; i < 20; i++) {
		counter = 0;
		// Sprawdz linie
		for (int j = 0; j < 10; j++) {
			if (field[i][j] == 'x') {
				counter++;
			}
		}
		if (counter == 10) {
			// Wyczysc linie
			deleted++;
			for (int l = 0; l < 10; l++) {
				field[i][l] = '.';
			}

			// Przesun pojedyncze elementy o jeden w dol
			for (int m = 0; m < blocks.size(); m++) {
				blocks[m]->moveBlock(*this, i);
			}

			// Przesun wszystko nad ta linia o jeden w dol
			for (int k = i; k > 0; k--) {
				for (int z = 0; z < 10; z++) {
					field[k][z] = field[k - 1][z];
				}
			}
		}
	}
	return deleted;
}

bool Field::isOver() {
	for (int i = 0; i < 10; i++) {
		if (field[0][i] == 'x') return true;
		// if(field[1][i] == 'x') return true;
	}
	return false;
}
