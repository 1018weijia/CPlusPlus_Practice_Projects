#pragma once
#include<iostream>
#include"small_rectangle.h"
#include"snake.h"
using namespace std;
int score = 0;
//公有继承小方格类,因为食物本身也是一个小方格
class food :public small_rectangle
{
public:
	food() :small_rectangle(0, 0)
	{
		//随机生成坐标
		pos_x = rand() % 80 * 10;//确保在屏幕显示范围之内,保证食物的坐标一定是10的整数倍
		pos_y = rand() % 80 * 10;//并且这个数字还比真实范围要小一些,原因是如果在边缘的话,很可能会撞墙死亡,影响游戏体验
	}
	void draw()override
	{
		setfillcolor(RED);//设置食物颜色为红色
		fillrectangle(pos_x, pos_y, pos_x + 10, pos_y + 10);
	}
	//改变食物的坐标,在每次吃完食物后需要重新出现一个新的食物,并且坐标需要改变
	void change_pos()
	{
		pos_x = rand() % 80 * 10;
		pos_y = rand() % 80 * 10;
	}
};
