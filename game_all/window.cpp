#include "window.h"
#include<iostream>
#include<graphics.h>
using namespace std;
#define WIDTH 60//�Ź���ÿһС��Ĵ�С
#define HEIGHT 60
window::window(int width, int height)
{
	this->width = width;
	this->height = height;
}

window::~window()
{
	closegraph();//�رմ��ڼ�������
}

void window::Show()
{
	initgraph(width, height);//���ɼ�Ϊ���ô������ɺ���
}
