#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class IBlock : public Block {
public:
	IBlock();
	 void rotateBlock(Field f);

};

