#include "Font.h"

bool font::InIt(int x, int y, string file, string name)
{
	if (!font.loadFromFile(file))
	{
		return false;
	}
	else
	{
		text.setFont(font);
		text.setString(name);
		text.setPosition(x, y);
		text.setCharacterSize(23);
	}
}

void font::draw(RenderWindow& window)
{
	window.draw(text);
}
