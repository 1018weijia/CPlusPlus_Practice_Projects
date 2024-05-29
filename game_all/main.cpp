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
		//���û�����sʱ����Ϸ��ʼ
		cout << "If you want to play the game ,Please enter  s" << endl;
		cout << "If not,Please enter other key" << endl;
		char c;
		cin >> c;
		if (c == 's')
		{
			//��������
			initgraph(900, 900, EX_SHOWCONSOLE);
			setbkcolor(WHITE);//���ñ�������ɫ
			//�������������
			srand(time(nullptr));
			game_scene scene;//��������
			//���û���Ҫ�˳���Ϸʱ����shift�������˳���Ϸ
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
			//�����»س���ʱ���ڹر�
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
		//���û�����sʱ����Ϸ��ʼ
		cout << "If you want to play the game ,Please enter s" << endl;
		cout << "If not,Please enter other key" << endl;
		char c;
		cin >> c;
		if (c == 's')
		{
			//����һ��������,ʹ�ô�С�պ�����9*9��С����
			window w(9 * WIDTH, 9 * HEIGHT);
			w.Show();//����
			//����һ��������
			Sudoku sudoku;
			//����һ����Ϣ��,���ڲ���������Ϣ
			ExMessage msg;
			BeginBatchDraw();//���øú���,��������
			while (1)//������δ�ɹ����ʱ,һֱ����
			{
				cleardevice();
				peekmessage(&msg, EM_MOUSE);
				//������������Ŀ
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
