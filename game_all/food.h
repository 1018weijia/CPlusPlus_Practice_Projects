#pragma once
#include<iostream>
#include"small_rectangle.h"
#include"snake.h"
using namespace std;
int score = 0;
//���м̳�С������,��Ϊʳ�ﱾ��Ҳ��һ��С����
class food :public small_rectangle
{
public:
	food() :small_rectangle(0, 0)
	{
		//�����������
		pos_x = rand() % 80 * 10;//ȷ������Ļ��ʾ��Χ֮��,��֤ʳ�������һ����10��������
		pos_y = rand() % 80 * 10;//����������ֻ�����ʵ��ΧҪСһЩ,ԭ��������ڱ�Ե�Ļ�,�ܿ��ܻ�ײǽ����,Ӱ����Ϸ����
	}
	void draw()override
	{
		setfillcolor(RED);//����ʳ����ɫΪ��ɫ
		fillrectangle(pos_x, pos_y, pos_x + 10, pos_y + 10);
	}
	//�ı�ʳ�������,��ÿ�γ���ʳ�����Ҫ���³���һ���µ�ʳ��,����������Ҫ�ı�
	void change_pos()
	{
		pos_x = rand() % 80 * 10;
		pos_y = rand() % 80 * 10;
	}
};
