#pragma once
#include<iostream>
#include"food.h"
#include"small_rectangle.h"
#include"snake.h"
//��Ϸ�����,�������ߺ�ʳ��
int stop_game = 0;
class game_scene
{
public:
	game_scene() {};
	//�������к���,���漯����������Ϸ��ʼ��Ҫִ�еĲ���,����Ϸ��ʼʱһֱ����,ֱ���û��˳�������Ϸ����
	void function()
	{
		BeginBatchDraw();//˫�����ͼ,�������������,���ֲ�����������Ļ�������Ļ������bug
		cleardevice();//����

		snake1.draw();//�����ߺ�ʳ��
		food1.draw();

		EndBatchDraw();
		//�ƶ�����,���ı���ͷ������
		snake1.snake_move();
		snakeEatFood();
		//��ȡ��Ϣ
		ExMessage msg = { 0 };//���岢��ʼ����Ϣ
		while (peekmessage(&msg, EX_KEY))
		{
			onMSg(msg);
		}
	}
	//��ȡ������Ϣ
	void onMSg(const ExMessage& msg)
	{
		//����м�����Ϣ
		if (msg.message == WM_KEYDOWN)
		{
			//�ı��ߵ��ƶ����� ��ȡ���̰��� 
			//�ж����ĸ�����,���������������ִ�в��� 
			if (msg.vkcode == VK_UP ||
				msg.vkcode == VK_DOWN ||
				msg.vkcode == VK_LEFT ||
				msg.vkcode == VK_RIGHT)
			{
				snake1.direction = msg.vkcode;
			}
			if (msg.vkcode == VK_SHIFT)
			{
				stop_game = 1;
			}

		}
	}
	//�ж����Ƿ�Ե���ʳ��
	void snakeEatFood()
	{
		if (snake1.snake_eat(food1))//����ߺ�ʳ���������ײ
		{
			//�ߵĳ�������
			snake1.snake_grow();
			//ʳ����������,λ�����
			food1.change_pos();
			//ÿ��һ��ʳ��,�÷�����5,��������÷�
			score += 5;
		}
	}
private:
	snake snake1;//�����߶����ʳ�����
	food food1;
};
