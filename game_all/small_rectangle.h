#pragma once
#include<iostream>
#include<easyx.h>//����easyxͷ�ļ�,����һЩ���ƴ��ڵĲ���
using namespace std;
#define side 10//�궨����εı߳�Ϊ10
//����һ����ʶ��,�жϸ����Ƿ����,������ı�����ֵ,������ʱʶ�𲢽�������
int isdeath = 0;
//С������
class small_rectangle
{
public:
	small_rectangle(int x, int y) :pos_x(x), pos_y(y), fill_color(BLUE) {};//���캯��
	small_rectangle() :small_rectangle(0, 0) {};//Ĭ�Ϲ���

	//����easyx�еĺ�������С����
	virtual void draw()
	{
		fillrectangle(pos_x, pos_y, pos_x + side, pos_y + side);//����С����
		setfillcolor(fill_color);//���÷���������ɫ
	}
	//С�����ƶ�(��ӵľ����ߵ��ƶ�)
	void Move(int x, int y)
	{
		pos_x += x;
		pos_y += y;
		if (pos_x > 900 || pos_y > 900 ||
			pos_x < 0 || pos_y < 0)
		{
			isdeath = 1;//����䷶Χ������ҳ�淶Χ,�򽫱�ʶ������
		}
	}
	//����Ƿ񷽸�ͷ���֮���Ƿ��ص�,������߳�ʳ��,ʳ��Ҳ��һ������
	bool meet(const small_rectangle& other)
	{
		return (pos_x == other.pos_x) && (pos_y == other.pos_y);
	}
public:
	int pos_x = 0;//����
	int pos_y = 0;
	COLORREF fill_color = BLUE;//�����ɫ
};