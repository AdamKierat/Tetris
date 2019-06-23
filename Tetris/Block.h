#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Graphics.hpp>
#include "Field.h"
#include <iostream>
#include <cstdlib>
using namespace sf;
using namespace std;

class Field;
class Block: public Drawable , public Transformable
{
public:
	// metoda poruszajaca blokiemn
	void move(float set_X, float set_Y);
	// Trzy metody sprawdzajace czy blok jest na krawędzi
	bool isOnLeft(RenderWindow &window);
	bool isOnRight(RenderWindow &window);
	bool isOnBottom(RenderWindow &window);
	//Zwraca 4 kierunki pozycji bloku
	Vector2f* getPosition();

	//Rysuje blok jesli znajduje sie w tablicy
	void drawBlock(RenderWindow &window, Field field);

	// Porusza blokiem w dol jesli znajduje sie w tablicy field
	//Metoda zadzaila tylko jesli klocek znajdzie sie w wierszu
	void moveBlock(Field F, int row);
	
	virtual void rotateBlock(Field F) = 0;
	// Dla klas dziedziczacych 

protected:
	RectangleShape blocks[4];
	int BRICK_SIZE;
	Texture tileTexture;

	
	int angle;

private:
	void draw(RenderTarget &target, RenderStates states)const;
};
#endif 