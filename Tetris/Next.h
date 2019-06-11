#ifndef NEXT_H
#define NEXT_H
#include <SFML/Graphics.hpp>
#include "IBlock.h"
#include "JBlock.h"
#include "OBlock.h"
#include "LBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
#include "SBlock.h"
#include "ZBlock.h"

using namespace sf;

class Next : public Drawable {
public:
	Next(int which);

	// Zmienia po opadnieciu na nastepny do naryswania
	void switchBlock(int which);

private:
	Font font;
	Text text;
	int current;
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
