#ifndef SHADOW_H
#define SHADOW_H
#include <SFML/Graphics.hpp>
#include "IBlock.h"
#include "JBlock.h"
#include "OBlock.h"
#include "LBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
#include "SBlock.h"
#include "Field.h"
using namespace sf;

class Shadow :public Drawable {
public:
	Shadow(Field f, Block* block, RenderWindow &window);
	void updateShadow(Field f, Block* block, RenderWindow &window);

private:
	Block* block;
	IBlock iBlock;
	JBlock jBlock;
	LBlock lBlock;
	OBlock oBlock;
	SBlock sBlock;
	ZBlock zBlock;
	TBlock tBlock;
	void draw(RenderTarget &target, RenderStates states) const;

};
#endif