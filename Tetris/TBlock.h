#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class TBlock :  public Block {
public:
	TBlock();
	 void rotateBlock(Field f);

};

