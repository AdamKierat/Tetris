#include "Shadow.h"

Shadow::Shadow(Field f, Block* block, RenderWindow &window) {
	this->block = block;
	while (!(block->isOnBottom(window))) {
		(this->block)->move(0, 30);
	}
}

void Shadow::updateShadow(Field f, Block* block, RenderWindow &window) {

}

void Shadow::draw(RenderTarget &target, RenderStates states) const {
	target.draw(*(this->block), states);
}

