#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class SBlock :  public Block {
public:
	SBlock();
	 void rotateBlock(Field f);

};

