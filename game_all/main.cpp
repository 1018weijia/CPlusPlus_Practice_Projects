#include<iostream>
#include"food.h"
#include"game_scene.h"
#include"small_rectangle.h"
#include"snake.h"
#include"window.h"
#include"button.h"
#include"Timer.h"
#include"Sudoku.h"
int main()
{
	cout << "		Welcome to play the games" << endl;
	cout << "		We have 2 games to be chosen" << endl;
	cout << "		They are	Gluttonous Snake		and		Sudoku " << endl;
	cout << "If you want to play Gluttonous Snake,Please enter 1" << endl;
	cout << "If you want to play Sudoku,Please enter 2" << endl;
	cout << "And if you do not want to play the game,please enter 0" << endl;
	int game_chosen = 0;
	cin >> game_chosen;
	if (game_chosen == 1)
	{
		cout << "		Hello,welcome to play Gluttonous Snake" << endl;
		//当用户输入s时，游戏开始
		cout << "If you want to play the game ,Please enter  s" << endl;
		cout << "If not,Please enter other key" << endl;
		char c;
		cin >> c;
		if (c == 's')
		{
			//创建窗口
			initgraph(900, 900, EX_SHOWCONSOLE);
			setbkcolor(WHITE);//设置背景版颜色
			//设置随机数种子
			srand(time(nullptr));
			game_scene scene;//创建对象
			//当用户想要退出游戏时按下shift键即可退出游戏
			cout << "		If you want to stop the game,please enter shift" << endl;
			cout << "		To close the graph ,you need to enter the Enter" << endl;
			while (true)
			{
				scene.function();
				Sleep(100);
				if (isdeath == 1)
				{
					cout << "		The snake is died.		" << endl;
					cout << "		Your Final score is:" << score << endl;
					cout << "		Looking forward to your next achievement" << endl;
					break;
				}
				if (stop_game == 1)
				{
					cout << "		you stop the game" << endl;
					cout << "		Your Final score is:" << score << endl;
					cout << "		Looking forward to your next achievement" << endl;
					break;
				}
			}
			//当按下回车键时窗口关闭
			getchar();
			closegraph();
		}
		else
		{
			cout << "OK,See you" << endl;
		}
	}
	else if (game_chosen == 2)
	{
		cout << "		Hello,welcome to play Sodoku" << endl;
		//当用户输入s时，游戏开始
		cout << "If you want to play the game ,Please enter s" << endl;
		cout << "If not,Please enter other key" << endl;
		char c;
		cin >> c;
		if (c == 's')
		{
			//定义一个窗口类,使得大小刚好容下9*9个小窗口
			window w(9 * WIDTH, 9 * HEIGHT);
			w.Show();//绘制
			//定义一个数独类
			Sudoku sudoku;
			//定义一个信息类,用于捕获鼠标的信息
			ExMessage msg;
			BeginBatchDraw();//调用该函数,避免屏闪
			while (1)//当数独未成功解出时,一直运行
			{
				cleardevice();
				peekmessage(&msg, EM_MOUSE);
				//画出数独的题目
				sudoku.DrawMap();
				if (sudoku.gameover())
				{
					cout << "You win" << endl;
					break;
				}
				sudoku.Mouse_to_text(msg);
				FlushBatchDraw();
			}
			EndBatchDraw();
			closegraph();
			cout << "gameover" << endl;
		}
		else
		{
			cout << "OK,See you" << endl;
		}
	}
	cout << "Bye~" << endl;
	return 0;
}
