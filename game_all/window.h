#pragma once
#include<iostream>
using namespace std;
//������
class window
{
public:
	window(int width, int height);
	~window();
	void Show();//��ʾ����
protected:
	int width;
	int height;
};