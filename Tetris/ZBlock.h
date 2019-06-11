#ifndef ZBlock_H
#define ZBlock_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class ZBlock :  public Block {
public:
	ZBlock();
	 void rotateBlock(Field f);

};
#endif
