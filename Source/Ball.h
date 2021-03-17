#pragma once

#include "Sprite.h"
#include "Sound.h"
#include <time.h>

constexpr auto tocdo = 0.1;


class Ball
{
public:
	sound vacham;
	bool InIt(int, int, string);//Load anh trai banh tu file.
	void Move(double,double);//Di chuyen trai banh 1 khoang nhat dinh.
	void ResetMove(double&, double&);//Tao lai huong di ban dau cho trai banh.
	void draw(RenderWindow&);
	Vector2f getPosition();
	void HandlingCollisions(Vector2f, Vector2f, Vector2f, double&, double&);//Xu ly va cham doi voi trai banh tren man hinh.
	void HandlingCollisionsAI(Vector2f, double&, double&, double&);//Xu ly va cham cho trai banh AI.
	//Trai banh nay se di truoc trai banh chinh 1 khoang de lay vi tri tiep them ma banh chinh se cham, tu do dieu khien thanh do cua may tinh den vi tri do.
private:
	sprite sprite;
};

