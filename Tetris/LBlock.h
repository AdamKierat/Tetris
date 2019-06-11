#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class LBlock :  public Block {
public:
	LBlock();
	 void rotateBlock(Field f);

};

