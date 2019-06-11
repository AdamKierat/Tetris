#ifndef OBLOCK_H
#define OBLOCK_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class OBlock :  public Block {
public:
	OBlock();
	 void rotateBlock(Field f);

};
#endif
