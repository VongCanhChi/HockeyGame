#pragma once
#include "Sprite.h"

constexpr auto bienTrai = 57;
constexpr auto bienPhai = 590 - 90;

class Paddle
{
public:
	bool InIt(int, int, string);
	void setOrigin(int, int);
	Vector2f getPosition();
	void draw(RenderWindow&);
	void MovePlayer(int&);//Dieu khien thanh do cua nguoi choi qua trai, phai khi nguoi choi an A hoac D.
	void MoveAI(int&, double);//Dieu khien thanh do cua may tinh di chuyen voi toc do bang voi toc do thanh do cua nguoi choi.
private:
	sprite paddle;
};

