#pragma once
#include<iostream>
#include<easyx.h>//引入easyx头文件,用于一些绘制窗口的操作
using namespace std;
#define side 10//宏定义矩形的边长为10
//定义一个标识符,判断该蛇是否出界,出界则改变其数值,在运行时识别并结束程序
int isdeath = 0;
//小方格类
class small_rectangle
{
public:
	small_rectangle(int x, int y) :pos_x(x), pos_y(y), fill_color(BLUE) {};//构造函数
	small_rectangle() :small_rectangle(0, 0) {};//默认构造

	//调用easyx中的函数绘制小方格
	virtual void draw()
	{
		fillrectangle(pos_x, pos_y, pos_x + side, pos_y + side);//绘制小矩形
		setfillcolor(fill_color);//设置方格的填充颜色
	}
	//小方格移动(间接的就是蛇的移动)
	void Move(int x, int y)
	{
		pos_x += x;
		pos_y += y;
		if (pos_x > 900 || pos_y > 900 ||
			pos_x < 0 || pos_y < 0)
		{
			isdeath = 1;//如果其范围超过了页面范围,则将标识符更改
		}
	}
	//检测是否方格和方格之间是否重叠,类比于蛇吃食物,食物也是一个方格
	bool meet(const small_rectangle& other)
	{
		return (pos_x == other.pos_x) && (pos_y == other.pos_y);
	}
public:
	int pos_x = 0;//坐标
	int pos_y = 0;
	COLORREF fill_color = BLUE;//填充颜色
};