#pragma once
#pragma once
#include<iostream>
#include<string>
#include<graphics.h>
#include<vector>
#include<ctime>
#include<array>
using namespace std;
#define WIDTH 60//九宫格每一小格的宽度和高度
#define HEIGHT 60

//定义按钮类,其是数独当中的每一个元素
class Button
{
public:
	//构造函数,数据成员包括起始点和宽,高,以及其颜色,按钮上的数字
	Button(int x = 0, int y = 0, int width_ = 60, int h = 60, COLORREF curColor = LIGHTGREEN, string text = "");
	//显示该按钮
	void Show();
	//判断鼠标是否停留在按钮上
	bool Mouse_is_in_Button(ExMessage& msg);
	//判断操作者是否点击了鼠标
	bool Click_Button(ExMessage& msg);
	//点击鼠标后要进行按钮上的数字的更改
	void SetText();

protected:
	//按钮画在窗口的哪个位置,因为共有9*9个按钮,每个按钮根据不同的位置而一一标识
	int x;
	int y;
	//按钮的高度和宽度
	int width_;
	int height_;
	//鼠标在按钮上时的颜色,和离开时的颜色
	COLORREF current_Color;
	COLORREF return_Color;
	//设置文本
	string text;
};