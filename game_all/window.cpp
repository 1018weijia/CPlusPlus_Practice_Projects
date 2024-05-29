#include "window.h"
#include<iostream>
#include<graphics.h>
using namespace std;
#define WIDTH 60//九宫格每一小格的大小
#define HEIGHT 60
window::window(int width, int height)
{
	this->width = width;
	this->height = height;
}

window::~window()
{
	closegraph();//关闭窗口即是析构
}

void window::Show()
{
	initgraph(width, height);//生成即为调用窗口生成函数
}
