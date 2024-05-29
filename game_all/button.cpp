#include "button.h"
#include "window.h"
#include"common.h"
#include<sstream>
#include<easyx.h>
#include<graphics.h>
using namespace std;
//构造函数
Button::Button(int x, int y, int w, int h, COLORREF cur_Color, string text)
{
	this->x = x;
	this->y = y;
	this->width_ = w;
	this->height_ = h;
	this->current_Color = cur_Color;
	this->text = text;
	this->return_Color = cur_Color;
}

//画出该按钮
void Button::Show()
{
	//将按钮画出来
	setfillcolor(this->current_Color);//设置填充颜色
	setlinecolor(BLACK);//设置线条颜色
	fillrectangle(x, y, x + width_, y + height_);//界定按钮的边界


	//把按钮上的内容显示出来
	settextstyle(height_, 0, "微软雅黑");//设置字体格式
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);

	//这里要计算一下文本和边框之间的空隙,从而使得文本所处位置更美观
	int x_gap = x + (width_ - textwidth(text.c_str())) / 2;//x_gap,y_gap分别是文本和按钮之间的横,纵向空隙
	int y_gap = y + (height_ - textheight(text.c_str())) / 2;
	outtextxy(x_gap, y_gap, text.c_str());//输出文本的内容
}

//判断鼠标是否在按钮上,从而决定是否要改变颜色来提示
bool Button::Mouse_is_in_Button(ExMessage& msg)
{
	//通过判断鼠标的位置是否在按钮的范围之内来实现
	if (msg.x >= x && msg.x < x + width_ &&
		msg.y >= y && msg.y < y + height_)
	{
		this->current_Color = LIGHTBLUE;//鼠标在按钮上,改变颜色
		return true;
	}
	this->current_Color = this->return_Color;//鼠标不在按钮上,还原颜色
	return false;
}

//判断鼠标是否点击
bool Button::Click_Button(ExMessage& msg)
{
	if (Mouse_is_in_Button(msg) && msg.message == WM_LBUTTONUP)
	{
		return true;
	}
	return false;
}

//文本改变
void Button::SetText()
{
	stringstream str_to_num(text);//创建流类对象
	int num = 0;
	str_to_num >> num;
	num++;//每次点击,数字增加1
	if (num > 9)//数独的数字范围是1~9,当超出数字9时,重新将其赋值回0
	{
		num = 0;
	}
	this->text = to_string(num);//最后还要把整数转换为字符串
}