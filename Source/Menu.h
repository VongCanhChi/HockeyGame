#ifndef MENU_H_
#define MENU_H_
#include "SFML/Graphics.hpp"
#include "Paddle.h"

class Menu
{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[2];
	sprite background;
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }


};

#endif