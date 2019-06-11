#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class JBlock :  public  Block {
public:
	JBlock();
	 void rotateBlock(Field f);

};

