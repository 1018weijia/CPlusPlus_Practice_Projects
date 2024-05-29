#include "button.h"
#include "window.h"
#include"common.h"
#include<sstream>
#include<easyx.h>
#include<graphics.h>
using namespace std;
//���캯��
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

//�����ð�ť
void Button::Show()
{
	//����ť������
	setfillcolor(this->current_Color);//���������ɫ
	setlinecolor(BLACK);//����������ɫ
	fillrectangle(x, y, x + width_, y + height_);//�綨��ť�ı߽�


	//�Ѱ�ť�ϵ�������ʾ����
	settextstyle(height_, 0, "΢���ź�");//���������ʽ
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);

	//����Ҫ����һ���ı��ͱ߿�֮��Ŀ�϶,�Ӷ�ʹ���ı�����λ�ø�����
	int x_gap = x + (width_ - textwidth(text.c_str())) / 2;//x_gap,y_gap�ֱ����ı��Ͱ�ť֮��ĺ�,�����϶
	int y_gap = y + (height_ - textheight(text.c_str())) / 2;
	outtextxy(x_gap, y_gap, text.c_str());//����ı�������
}

//�ж�����Ƿ��ڰ�ť��,�Ӷ������Ƿ�Ҫ�ı���ɫ����ʾ
bool Button::Mouse_is_in_Button(ExMessage& msg)
{
	//ͨ���ж�����λ���Ƿ��ڰ�ť�ķ�Χ֮����ʵ��
	if (msg.x >= x && msg.x < x + width_ &&
		msg.y >= y && msg.y < y + height_)
	{
		this->current_Color = LIGHTBLUE;//����ڰ�ť��,�ı���ɫ
		return true;
	}
	this->current_Color = this->return_Color;//��겻�ڰ�ť��,��ԭ��ɫ
	return false;
}

//�ж�����Ƿ���
bool Button::Click_Button(ExMessage& msg)
{
	if (Mouse_is_in_Button(msg) && msg.message == WM_LBUTTONUP)
	{
		return true;
	}
	return false;
}

//�ı��ı�
void Button::SetText()
{
	stringstream str_to_num(text);//�����������
	int num = 0;
	str_to_num >> num;
	num++;//ÿ�ε��,��������1
	if (num > 9)//���������ַ�Χ��1~9,����������9ʱ,���½��丳ֵ��0
	{
		num = 0;
	}
	this->text = to_string(num);//���Ҫ������ת��Ϊ�ַ���
}