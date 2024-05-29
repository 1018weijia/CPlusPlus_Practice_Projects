#pragma once
#include<iostream>
using namespace std;
//窗口类
class window
{
public:
	window(int width, int height);
	~window();
	void Show();//显示窗口
protected:
	int width;
	int height;
};