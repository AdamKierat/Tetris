#ifndef IBlock_H
#define IBlock_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Field.h"
using namespace sf;


class IBlock : public Block {
public:
	IBlock();
	 void rotateBlock(Field f);

};
#endif 
