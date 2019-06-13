#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Field.h"
#include "LBlock.h"
#include "JBlock.h"
#include "IBlock.h"
#include "ZBlock.h"
#include "SBlock.h"
#include "OBlock.h"
#include "TBlock.h"
#include "Next.h"
#include "Stats.h"
#include "Shadow.h"


using namespace std;
using namespace sf;


class Game {
public:

	Game();
	void start(RenderWindow &window); //game start
	void over(int i, Field field, vector<Block*> blocks, Stats stats, Next nextWindow, RenderWindow &window); //game over

private:

	RenderWindow window;
};
#endif
