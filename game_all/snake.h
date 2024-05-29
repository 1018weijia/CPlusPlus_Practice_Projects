#pragma once
#include<iostream>
#include<vector>
#include"small_rectangle.h"
//公有继承小方格类,因为蛇只是一堆小方格的集合体,所以可以用vector来存储
class snake :public small_rectangle
{
public:
	snake() :snake(0, 0) {}//默认构造函数
	//蛇除了由一堆小方格组成,用vector来表示,蛇头还具有方向
	snake(int x, int y) :small_rectangle(x, y), direction(VK_DOWN)//默认向下移动
	{
		//初始化三节小方块,表示蛇身,以边长10递增
		snake_body.push_back(small_rectangle(20, 0));
		snake_body.push_back(small_rectangle(10, 0));
		snake_body.push_back(small_rectangle(0, 0));
	}
	void draw()override//函数重载
	{
		for (int i = 0; i < snake_body.size(); i++)
		{
			snake_body[i].draw();//直接用循环调用即可
		}
	}
	//检测蛇头是否吃到了食物
	bool snake_eat(const small_rectangle& food)
	{
		return snake_body[0].meet(food);
	}
	//当蛇吃到食物后,蛇的长度增加一节
	void snake_grow()
	{
		snake_body.push_back(small_rectangle());
	}
	//蛇的移动
	void snake_move()
	{
		//蛇的身体跟蛇头移动,这里注意要从后往前赋值,有点类似数组的后移操作
		for (int i = snake_body.size() - 1; i > 0; i--)
		{
			snake_body[i] = snake_body[i - 1];
		}
		//移动蛇头,按照键盘的输入来更改移动方向
		switch (direction)
		{
		case VK_UP://分别向上,向下,向左,向右移动,注意这里是以左上角为原点
			snake_body[0].Move(0, -10);
			break;
		case VK_DOWN:
			snake_body[0].Move(0, 10);
			break;
		case VK_LEFT:
			snake_body[0].Move(-10, 0);
			break;
		case VK_RIGHT:
			snake_body[0].Move(10, 0);
			break;
		default:
			break;
		}
	}

public:
	int direction;		//蛇的方向,用整型表示,因为查阅了资料发现表示上下左右键的就是数字

private:
	//用vector来存储,其中元素是小方块,因为不知玩家会把长度玩到多少,所以用动态容器
	vector<small_rectangle> snake_body;
};

