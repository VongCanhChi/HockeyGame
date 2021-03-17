#include "Game.h"
#include "Menu.h"
#include "Paddle.h"
#include "Windows.h"

int main()
{
	int test = 0;
	int dx = 220;
	int dy = 770;
	int a = 220;
	int b = 10;
	double u = 1;
	double v = -1;
	double BanhAo_x = 1;
	double BanhAo_y = -1;
	double mucTieu;	
	sf::RenderWindow window(sf::VideoMode(595, 805), L"HockeyGame", Style::Close); // Khung game

	//Thiet ke giao dien game
	sprite table;
	table.InIt(0, 0, "AssetGame\\Matban.jpg");

	Paddle paddle1,paddle2;
	paddle1.InIt(dx, dy, "AssetGame\\GiaDo.png");
	paddle1.setOrigin(50,0);
	paddle2.InIt(a, b, "AssetGame\\GiaDo.png");
	paddle2.setOrigin(50, 0);
	
	Ball ball1;
	ball1.InIt(275, 370, "AssetGame\\2.png");
	Ball ball2;
	ball2.InIt(275, 370, "AssetGame\\2.png");

	sprite messeagewin;
	font f1;
	f1.InIt(10, 357, "brushsbi.ttf", "Computer: ");
	font f2;
	f2.InIt(10, 390, "brushsbi.ttf", "You: ");
	font f3;
	f3.InIt(70, 390, "brushsbi.ttf", "");
	font f4;
	f4.InIt(120, 357, "brushsbi.ttf", "");

	sf::Image Icon;//Tao icon cho game.
	Icon.loadFromFile("AssetGame\\icon.jpg");
	window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());

	sound win;//Am thnah trong game.
	Game game;
	Menu menu(595, 805);
	win.soundPlay(win.backgroundsound);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					win.soundPlay(win.choose);
					switch (menu.GetPressedItem())
					{
					    case 0:
					    {
							int score1 = 1;
							int score2 = 1;
							while (window.isOpen())
							{
								window.setFramerateLimit(300); // So lan lap tren 1 giay.
								
								paddle1.InIt(dx, dy, "AssetGame\\GiaDo.png");
								paddle2.InIt(a, b, "AssetGame\\GiaDo.png");

								paddle1.MovePlayer(dx); //Xu li nhap ban phim
								Vector2f dAo = ball2.getPosition();
								Vector2f d2 = paddle1.getPosition();
								Vector2f d3 = paddle2.getPosition();

								game.xuLyBanhAo(test, ball2, BanhAo_x, BanhAo_y);

								//Chuyen dong cua banh
								ball1.Move(u, v);
								Vector2f d = ball1.getPosition();
								ball1.HandlingCollisions(d, d2, d3, u, v);
								ball2.HandlingCollisionsAI(dAo, BanhAo_x, BanhAo_y, mucTieu);
								ball2.Move(BanhAo_x, BanhAo_y);
								paddle2.MoveAI(a, mucTieu);
								//Xu li ghi diem, thang, thua.
								if (d.y < 7) {
									if (score1 == 5)
									{
										game.xuLyThang(window, messeagewin, main);
									}
									win.soundPlay(win.win1);
									game.xuLyDiem(window, score1, f3, test, 390, ball1, ball2, u, v, BanhAo_x, BanhAo_y);
								}
								if (d.y > 765) {
									if (score2 == 5)
									{
										game.xuLyThua(window, messeagewin, main);
									}
									win.soundPlay(win.lose1);
									game.xuLyDiem(window, score2, f4, test, 357, ball1, ball2, u, v, BanhAo_x, BanhAo_y);
								}

								if (Keyboard::isKeyPressed(Keyboard::Escape)) //Nhan esc de thoat ra ngoai menu.
								{
									window.close();
									main();//Tro ve menu chinh.
								}

								window.clear();
								table.draw(window);
								paddle1.draw(window);
								paddle2.draw(window);
								ball1.draw(window);
								f1.draw(window);
								f2.draw(window);
								f3.draw(window);
								f4.draw(window);
								window.display();
							}
							return EXIT_SUCCESS;
							break;
                        } 
					    case 1:
						    window.close();
						    break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
			{
				window.close(); 
			}
				break;
			}
		}
		window.clear();
		menu.draw(window);
		window.display();
	}
}
