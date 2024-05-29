#pragma once
#include<iostream>
#include<vector>
#include"small_rectangle.h"
//���м̳�С������,��Ϊ��ֻ��һ��С����ļ�����,���Կ�����vector���洢
class snake :public small_rectangle
{
public:
	snake() :snake(0, 0) {}//Ĭ�Ϲ��캯��
	//�߳�����һ��С�������,��vector����ʾ,��ͷ�����з���
	snake(int x, int y) :small_rectangle(x, y), direction(VK_DOWN)//Ĭ�������ƶ�
	{
		//��ʼ������С����,��ʾ����,�Ա߳�10����
		snake_body.push_back(small_rectangle(20, 0));
		snake_body.push_back(small_rectangle(10, 0));
		snake_body.push_back(small_rectangle(0, 0));
	}
	void draw()override//��������
	{
		for (int i = 0; i < snake_body.size(); i++)
		{
			snake_body[i].draw();//ֱ����ѭ�����ü���
		}
	}
	//�����ͷ�Ƿ�Ե���ʳ��
	bool snake_eat(const small_rectangle& food)
	{
		return snake_body[0].meet(food);
	}
	//���߳Ե�ʳ���,�ߵĳ�������һ��
	void snake_grow()
	{
		snake_body.push_back(small_rectangle());
	}
	//�ߵ��ƶ�
	void snake_move()
	{
		//�ߵ��������ͷ�ƶ�,����ע��Ҫ�Ӻ���ǰ��ֵ,�е���������ĺ��Ʋ���
		for (int i = snake_body.size() - 1; i > 0; i--)
		{
			snake_body[i] = snake_body[i - 1];
		}
		//�ƶ���ͷ,���ռ��̵������������ƶ�����
		switch (direction)
		{
		case VK_UP://�ֱ�����,����,����,�����ƶ�,ע�������������Ͻ�Ϊԭ��
			snake_body[0].Move(0, -10);
			break;
		case VK_DOWN:
			snake_body[0].Move(0, 10);
			break;
		case VK_LEFT:
			snake_body[0].Move(-10, 0);
			break;
		case VK_RIGHT:
			snake_body[0].Move(10, 0);
			break;
		default:
			break;
		}
	}

public:
	int direction;		//�ߵķ���,�����ͱ�ʾ,��Ϊ���������Ϸ��ֱ�ʾ�������Ҽ��ľ�������

private:
	//��vector���洢,����Ԫ����С����,��Ϊ��֪��һ�ѳ����浽����,�����ö�̬����
	vector<small_rectangle> snake_body;
};

