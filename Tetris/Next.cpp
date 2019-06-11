#include "Next.h"

Next::Next(int which) {
	font.loadFromFile("fonts/DottyShadow.ttf");
	text.setCharacterSize(40);
	text.setFont(font);
	text.move(356, 47);
	text.setString("Next\npiece");
	current = which;
	lBlock.move(240, 180);
	oBlock.move(270, 180);
	iBlock.move(270, 180);
	sBlock.move(240, 180);
	zBlock.move(270, 180);
	tBlock.move(270, 180);
	jBlock.move(300, 180);

}

void Next::switchBlock(int which) {
	current = which;
}

void Next::draw(RenderTarget &target, RenderStates states) const {
	target.draw(this->text, states);
	switch (current) {
	case 0:
		target.draw(this->lBlock, states);
		break;

	case 1:
		target.draw(this->iBlock, states);
		break;

	case 2:
		target.draw(this->zBlock, states);
		break;

	case 3:
		target.draw(this->oBlock, states);
		break;

	case 4:
		target.draw(this->sBlock, states);
		break;

	case 5:
		target.draw(this->jBlock, states);
		break;

	case 6:
		target.draw(this->tBlock, states);
		break;

	}

}
