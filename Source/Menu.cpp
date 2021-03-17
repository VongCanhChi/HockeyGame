#include "Menu.h"
#include "Game.h"
#include "Sprite.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("brushsbi.ttf"))
	{
		// handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setCharacterSize(80);
	menu[0].setPosition(sf::Vector2f(width / 2 - 90, height / (3 + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setCharacterSize(80);
	menu[1].setPosition(sf::Vector2f(width / 2 - 90, height / (3 + 1) * 2));

	background.InIt(0, 0, "AssetGame\\menu.jpg");

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	background.draw(window);
	for (int i = 0; i < 2; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < 2)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
