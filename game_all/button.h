#pragma once
#pragma once
#include<iostream>
#include<string>
#include<graphics.h>
#include<vector>
#include<ctime>
#include<array>
using namespace std;
#define WIDTH 60//�Ź���ÿһС��Ŀ�Ⱥ͸߶�
#define HEIGHT 60

//���尴ť��,�����������е�ÿһ��Ԫ��
class Button
{
public:
	//���캯��,���ݳ�Ա������ʼ��Ϳ�,��,�Լ�����ɫ,��ť�ϵ�����
	Button(int x = 0, int y = 0, int width_ = 60, int h = 60, COLORREF curColor = LIGHTGREEN, string text = "");
	//��ʾ�ð�ť
	void Show();
	//�ж�����Ƿ�ͣ���ڰ�ť��
	bool Mouse_is_in_Button(ExMessage& msg);
	//�жϲ������Ƿ��������
	bool Click_Button(ExMessage& msg);
	//�������Ҫ���а�ť�ϵ����ֵĸ���
	void SetText();

protected:
	//��ť���ڴ��ڵ��ĸ�λ��,��Ϊ����9*9����ť,ÿ����ť���ݲ�ͬ��λ�ö�һһ��ʶ
	int x;
	int y;
	//��ť�ĸ߶ȺͿ��
	int width_;
	int height_;
	//����ڰ�ť��ʱ����ɫ,���뿪ʱ����ɫ
	COLORREF current_Color;
	COLORREF return_Color;
	//�����ı�
	string text;
};