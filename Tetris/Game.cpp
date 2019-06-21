#include "Game.h"

int currentBlock, nextBlock;

// Losuje jeden z siedmiu mozliwych klockow, ktory pojawi sie gdy bierzacy klocek zostanie ulozony
void selectBlock(vector<Block*> &blocks) {
	switch (currentBlock) {
	case 0:
		blocks.push_back(new LBlock);
		break;

	case 1:
		blocks.push_back(new IBlock);
		break;

	case 2:
		blocks.push_back(new ZBlock);
		break;

	case 3:
		blocks.push_back(new OBlock);
		break;

	case 4:
		blocks.push_back(new SBlock);
		break;

	case 5:
		blocks.push_back(new JBlock);
		break;

	case 6:
		blocks.push_back(new TBlock);
		break;

	}
	currentBlock = nextBlock;
}

Game::Game() {

}

void Game::start(RenderWindow &window) {
	int deleted = 0;

	srand(time(NULL));
	vector<Block*> blocks;
	Stats stats;
	currentBlock = rand() % 7;
	nextBlock = rand() % 7;

	Next nextWindow(nextBlock);

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("images/background.png");
	RectangleShape background(Vector2f(510, 600));
	background.setTexture(&backgroundTexture);

	Field field;
	// field.display();

	// Indeks w wektorze blocks
	int i = 0;

	Clock clock;
	float time, timer = 0, delay = 0.5;

	selectBlock(blocks);

	// Shadow shadow(field, blocks[i], window);
	while (window.isOpen()) {
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e)) {
			switch (e.type) {
			case Event::Closed:
				window.close();
				break;

				// Jesli wcisnalem jakis klawisz
			case Event::KeyPressed:
				switch (e.key.code) {
				case Keyboard::Escape:
					window.close();
					break;

				case Keyboard::Left:
					if (!(blocks[i]->isOnLeft(window)) && !(field.isOnLeft(blocks[i]))) {
						blocks[i]->move(-30, 0);
					}
					break;

				case Keyboard::Right:
					if (!(blocks[i]->isOnRight(window)) && !(field.isOnRight(blocks[i]))) {
						blocks[i]->move(30, 0);
					}
					break;

				case Keyboard::Down:
					if (!(blocks[i]->isOnBottom(window)) && !(field.isOnBlock(blocks[i]))) {
						blocks[i]->move(0, 30);
					}
					break;

				case Keyboard::Up:
					blocks[i]->rotateBlock(field);
					break;

				case Keyboard::Space:
					while (!(blocks[i]->isOnBottom(window)) && !(field.isOnBlock(blocks[i]))) blocks[i]->move(0, 30);
					// Zaktualizuj pole charow
					field.update(blocks[i]);
					if (field.isOver()) {
						this->over(i, field, blocks, stats, nextWindow, window);
					}
					// Sprawdz czy przegralem
					deleted = field.checkLines(blocks);
					stats.updateStats(deleted, delay);
					// field.display();

					// Wylosuj jaki klocek stworzyc
					selectBlock(blocks);
					i++;

					// Zaktualizuj okno nastepnego klocka
					nextWindow.switchBlock(nextBlock);
					nextBlock = rand() % 7;
					break;

				}
				break;

			}
		}

		// Pojedyncza jednostka czasu
		if (timer > delay) {
			timer = 0;
			// Jesli jestem na dole to stworz nowy klocek
			if (blocks[i]->isOnBottom(window) || field.isOnBlock(blocks[i])) {
				//  Zaktualizuj pole charow
				field.update(blocks[i]);
				if (field.isOver()) {
					this->over(i, field, blocks, stats, nextWindow, window);
				}
				deleted = field.checkLines(blocks);
				stats.updateStats(deleted, delay);
				// field.display();

				// Wylosuj jaki klocek stworzyc
				selectBlock(blocks);
				i++;

				// Zaktualizuj okno nastepnego klocka
				nextWindow.switchBlock(nextBlock);
				nextBlock = rand() % 7;
			}
			else {
				blocks[i]->move(0, 30);
			}
		}

		window.clear(Color::Black);

		// Narysuj tlo
		window.draw(background);

		// Narysuj bierzacy klocek
		window.draw(*blocks[i]);

		// Narysuj cien klocka
		// window.draw(shadow);

		// Narysuj wszystkie lezace klocki
		for (int j = 0; j < i; j++) {
			blocks[j]->drawBlock(window, field);
		}

		// Narysuj okno z nastpenym klockiem
		window.draw(nextWindow);

		// Narysuj statystyki
		window.draw(stats);

		window.display();
	}
}

void Game::over(int i, Field field, vector<Block*> blocks, Stats stats, Next nextWindow, RenderWindow &window) {
	Texture backgroundTexture;
	backgroundTexture.loadFromFile("images/background.png");
	RectangleShape background(Vector2f(510, 600));
	background.setTexture(&backgroundTexture);

	Font font;
	Text gameOver, press;
	gameOver.move(50, 240);
	gameOver.setCharacterSize(70);
	font.loadFromFile("fonts/DottyShadow.ttf");
	press.setFont(font);
	press.setString("Press R to restart");
	press.move(80, 340);
	gameOver.setFont(font);
	gameOver.setString("Game Over");

	while (window.isOpen()) {

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == e.Closed) window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::R)) {
			this->start(window);
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			this->start(window);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
			window.close();
		}

		window.draw(background);

		// Narysuj bierzacy klocek
		window.draw(*blocks[i]);

		// Narysuj cien klocka
		// window.draw(shadow);

		// Narysuj wszystkie lezace klocki
		for (int j = 0; j < i; j++) {
			blocks[j]->drawBlock(window, field);
		}

		// Narysuj okno z nastpenym klockiem
		window.draw(nextWindow);

		// Narysuj statystyki
		window.draw(stats);

		window.draw(gameOver);
		window.draw(press);
		window.display();
	}

}
