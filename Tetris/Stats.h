#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;
using namespace std;

class Stats : public Drawable {
public:
	Stats();

	void updateStats(int deleted, float &delay);

private:
	
	int levelInt, scoreInt, linesInt;
	Font font;
	Text score, scoreCount;
	Text level, levelCount;
	Text lines, linesCount;
	void draw(RenderTarget &target, RenderStates states) const;
	
};

