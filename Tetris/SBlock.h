#ifndef SBLOCK_H
#define SBLOCK_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class SBlock :  public Block {
public:
	SBlock();
	 void rotateBlock(Field f);

};
#endif 
