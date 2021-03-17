#include "Paddle.h"

bool Paddle::InIt(int x, int y, string file)
{
	if (paddle.InIt(x, y, file) == false)
	{
		return false;
	}
}

void Paddle::setOrigin(int x, int y)
{
	paddle.setOrigin(x, y);
}

Vector2f Paddle::getPosition()
{
	return paddle.getPosition();
}

void Paddle::draw(RenderWindow& window)
{
	paddle.draw(window);
}

void Paddle::MovePlayer(int& dx)
{
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (dx >= bienTrai) {
			dx -= 1;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (dx <= bienPhai) {
			dx += 1;
		}
	}
}

void Paddle::MoveAI(int& a, double muctieu)
{
	if (a > muctieu) {
		if (a >= bienTrai) {
			a -= 1;
		}
	}
	if (a < muctieu) {
		if (a <= bienPhai) {
			a += 1;
		}
	}
}
