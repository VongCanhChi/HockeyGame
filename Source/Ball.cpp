#include "Ball.h"


bool Ball::InIt(int x, int y, string file)
{
	if (sprite.InIt(x,y,file)==false)
	{
		return false;
	}
}

void Ball::Move(double u, double v)
{
	sprite.Move(u, v);
}

void Ball::ResetMove(double& u, double& v)
{
	srand((int)time(0));
	u = pow(-1,rand());
	v = pow(-1, rand());
}

void Ball::draw(RenderWindow& window)
{
	sprite.draw(window);
}

Vector2f Ball::getPosition()
{
	return sprite.getPosition();
}

void Ball::HandlingCollisions(Vector2f d, Vector2f d2, Vector2f d3, double& u, double& v)
{
	if (d.x < 1 || d.x > 546)
	{
		u = -u;
		vacham.soundPlay(vacham.amvachamcanhban);

	}
	if (d.y >= 7 && d.y <= 11 && d.x >= d3.x - 70 && d.x <= d3.x + 90)
	{
		v = -v;
		vacham.soundPlay(vacham.amvachamthanhdo);
	}

	if (d.y >= 752 && d.y <= 757 && d.x >= d2.x -70 && d.x <= d2.x + 90) {//Tang toc do trai banh khi va cham vao thanh do cua nguoi choi.
		if (u < 0) {
			u -= tocdo;
		}
		else {
			u += tocdo;
		}
		if (v < 0) {
			v -= tocdo;
		}
		else {
			v += tocdo;
		}
		v = -v;
		vacham.soundPlay(vacham.amvachamthanhdo);
	}
}

void Ball::HandlingCollisionsAI(Vector2f d, double& u, double& v, double& mucTieu)
{
	if (d.x < 1 || d.x > 546)
	{
		u = -u;
	}
	if (d.y >= 7 && d.y <= 11)
	{
		mucTieu = d.x;
		v = -v;
	}

	if (d.y >= 752 && d.y <= 757) {//Tang toc do trai banh khi va cham vao thanh do cua nguoi choi.
		if (u < 0) {
			u -= tocdo;
		}
		else {
			u += tocdo;
		}
		if (v < 0) {
			v -= tocdo;
		}
		else {
			v += tocdo;
		}
		v = -v;
	}	
}
