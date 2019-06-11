#include "Stats.h"

Stats::Stats() {
	levelInt = 1;
	scoreInt = 0;
	linesInt = 0;
	font.loadFromFile("fonts/DottyShadow.ttf");

	score.setFont(font);
	level.setFont(font);
	lines.setFont(font);

	scoreCount.setFont(font);
	levelCount.setFont(font);
	linesCount.setFont(font);

	score.setString("Score");
	scoreCount.setString("0");
	level.setString("Level");
	levelCount.setString("1");
	lines.setString("Lines");
	linesCount.setString("0");

	level.move(368, 350);
	levelCount.move(368, 380);

	score.move(372, 430);
	scoreCount.move(372, 460);

	lines.move(372, 510);
	linesCount.move(372, 540);
}

void Stats::updateStats(int deleted, float &delay) {
	string countedLines, countedScore, countedLevel;

	linesInt += deleted;
	stringstream conversion;
	conversion.clear();
	conversion << linesInt;
	conversion >> countedLines;
	linesCount.setString(countedLines);

	if (deleted > 0)
		scoreInt += levelInt * 10 * deleted;

	conversion.clear();
	conversion << scoreInt;
	conversion >> countedScore;
	scoreCount.setString(countedScore);

	int prev = levelInt;
	levelInt = (linesInt / 10) + 1;

	// Jesli level sie zwiekszyl, zwieksz delay
	if (levelInt > prev) delay = delay - 0.02;
	conversion.clear();
	conversion << levelInt;
	conversion >> countedLevel;
	levelCount.setString(countedLevel);

}

void Stats::draw(RenderTarget &target, RenderStates states) const {
	target.draw(this->score, states);
	target.draw(this->scoreCount, states);

	target.draw(this->level, states);
	target.draw(this->levelCount, states);

	target.draw(this->lines, states);
	target.draw(this->linesCount, states);

}
