#ifndef Game_H_
#define Game_H_

#include <sstream>
#include "Font.h"
#include "Ball.h"


class Game
{
public:
	void xuLyDiem(sf::RenderWindow& window, int& score2, font& f4, int& test, int position, Ball& ball1, Ball& ball2, double& u, double& v, double& BanhAo_x, double& BanhAo_y);
	void xuLyThua(sf::RenderWindow& window, sprite& messeagewin, int main());
	void xuLyThang(sf::RenderWindow& window, sprite& messeagewin, int main());
	void xuLyBanhAo(int& test, Ball& ball2, double& BanhAo_x, double& BanhAo_y);//Xu ly khi bat dau moi lan choi, dieu khien trai banh aoo cham vao thanh do.
	//Sau do moi cho trai banh chinh di chuyen theo huong ban dau ma banh ao da di, thanh do cua may tinh se di chuyen den vi tri ma banh ao vua cham vao.
};

#endif