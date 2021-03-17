#include "Sprite.h"

bool sprite::InIt(int x, int y, string name)
{
	if (!texture.loadFromFile(name))
	{
		return false;
	}
	else
	{
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}
	return true;
}

Vector2f sprite::getPosition()
{
	return sprite.getPosition();
}

void sprite::setOrigin(int x, int y)
{
	sprite.setOrigin(x, y);
}

void sprite::Move(double x, double y)
{
	sprite.move(x, y);
}

void sprite::draw(RenderWindow& window)
{
	window.draw(sprite);
}
