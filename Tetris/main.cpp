#include "Game.h"

int WIDTH = 300;
int HEIGHT = 600;

int main() {

	Game tetris;
	RenderWindow window(VideoMode(WIDTH + 210, HEIGHT), "Tetris");
	tetris.start(window);

	return 0;
}
