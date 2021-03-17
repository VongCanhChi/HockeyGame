#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class sprite
{
private:
	Texture texture;
	Sprite sprite;
public:
	bool InIt(int, int, string);

	Vector2f getPosition();
	void setOrigin(int, int);
	void Move(double, double);
	void draw(RenderWindow&);
};
