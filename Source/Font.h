#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class font
{
private:
	Font font;
	Text text;
public:
	bool InIt(int, int, string, string);//Load font chu tu file.
	void draw(RenderWindow&);//In chu len man hinh.
};


