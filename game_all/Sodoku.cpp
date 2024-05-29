#include "Sudoku.h"
#include"button.h"
#include"timer.h"

Sudoku::Sudoku()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			int x = WIDTH * j;
			int y = HEIGHT * i;
			if (map[i][j] != 0)
			{
				//不可修改的绿色
				buttons_vec.push_back(make_pair<bool, Button*>(false, new Button(x, y, WIDTH, HEIGHT, LIGHTGREEN, to_string(map[i][j]))));
			}
			else
			{
				//可修改的红色
				buttons_vec.push_back(make_pair<bool, Button*>(true, new Button(x, y, WIDTH, HEIGHT, RED, to_string(map[i][j]))));
			}
		}
	}
}

void Sudoku::DrawMap()
{
	for (auto v : buttons_vec)
	{
		v.second->Show();
	}
}
//返回是按的哪个按钮
int Sudoku::ClickButton(ExMessage& msg)
{
	for (int i = 0; i < buttons_vec.size(); i++)
	{
		if (buttons_vec[i].second->Click_Button(msg) == true)
		{
			return i;
		}
	}
	return -1;
}

void Sudoku::Mouse_to_text(ExMessage& msg)
{
	int pos = ClickButton(msg);
	if (pos != -1 && buttons_vec[pos].first == true && Timer::my_Timer(100, 0))
	{
		buttons_vec[pos].second->SetText();
	}
}

//思路：判断除自身之外，是否还有别的数字和自身相同
bool Sudoku::gameover()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			//横向
			for (int n = 0; n < 9; n++)
			{
				if (n != j && map[i][n] == map[i][j])//首先判断是否为自己本身，再判断是否有重复的数字
				{
					return false;
				}
			}
			//纵向
			for (int m = 0; m < 9; m++)
			{
				if (m != i && map[m][j] == map[i][j])
				{
					return false;
				}
			}

			//九宫格判断
			//每一个九宫格中数字定位到起始位置
			int p = i / 3 * 3;
			int q = j / 3 * 3;
			for (int x = p; x < p + 3; x++)
			{
				for (int y = q; y < q + 3; y++)
				{
					if (x != i && map[x][y] == map[i][j])
						return false;
				}
			}
		}
	}
	return true;
}
