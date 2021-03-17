#include "Game.h"
#include <windows.h>


sound win;

void Game::xuLyDiem(sf::RenderWindow& window, int& score2, font& f4, int& test, int position, Ball& ball1, Ball& ball2, double& u, double& v, double& BanhAo_x, double& BanhAo_y)
{
	std::stringstream ss;
	ss << score2;
	score2++;//Tang them 1 diem.
	f4.InIt(120, position, "brushsbi.ttf", ss.str());//Ghi diem len man hinh.

	window.display();
	ball1.ResetMove(u, v);//Tao huong di moi cho trai banh.
	BanhAo_x = u;
	BanhAo_y = v;
	test = 0;
	ball1.InIt(275, 370, "AssetGame\\2.png");//Tra trai banh ve vi tri xuat phat.
	ball2.InIt(275, 370, "AssetGame\\2.png");
	Sleep(2000);
}

void Game::xuLyThua(sf::RenderWindow& window, sprite& messeagewin, int main())
{
	messeagewin.InIt(120, 220, "AssetGame\\lose.png");
	messeagewin.draw(window);
	window.display();//Hien thi hinh anh bao thuc cuoc.

	win.soundPlay(win.lose);//Am thanh khi thua cuoc.
	Sleep(3000);//Dung lai 1 khoang truoc khi tro ve menu chinh.
	if (Keyboard::Return)
	{
		window.close();
		main();//Goi lai ham main de tro ve menu.
	}
}

void Game::xuLyThang(sf::RenderWindow& window, sprite& messeagewin, int main())
{
	messeagewin.InIt(30, 220, "AssetGame\\win2.png");
	messeagewin.draw(window);
	window.display();//Hien thi hinh anh bao thang cuoc.

	win.soundPlay(win.win);//Phat am thanh thang cuoc.
	Sleep(3000);
	if (Keyboard::Enter)
	{
		window.close();
		main();//Tro ve menu chinh.
	}
}

void Game::xuLyBanhAo(int& test, Ball& ball2, double& BanhAo_x, double& BanhAo_y)
{
	while (test == 0) {
		Vector2f dAo = ball2.getPosition();
		if (dAo.y == 752 || dAo.y == 12) {
			test = 1;
			break;
		}
		if (dAo.x < 1 || dAo.x > 546)
		{
			BanhAo_x = -BanhAo_x;
		}
		ball2.Move(BanhAo_x, BanhAo_y);
	}
}