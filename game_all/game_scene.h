#pragma once
#include<iostream>
#include"food.h"
#include"small_rectangle.h"
#include"snake.h"
//游戏面板类,包含有蛇和食物
int stop_game = 0;
class game_scene
{
public:
	game_scene() {};
	//定义运行函数,里面集成了所有游戏开始后要执行的操作,在游戏开始时一直运行,直到用户退出或者游戏结束
	void function()
	{
		BeginBatchDraw();//双缓冲绘图,这里查阅了资料,发现不用这个函数的话会有屏幕闪动的bug
		cleardevice();//清屏

		snake1.draw();//绘制蛇和食物
		food1.draw();

		EndBatchDraw();
		//移动蛇身,并改变蛇头的坐标
		snake1.snake_move();
		snakeEatFood();
		//获取消息
		ExMessage msg = { 0 };//定义并初始化消息
		while (peekmessage(&msg, EX_KEY))
		{
			onMSg(msg);
		}
	}
	//获取键盘消息
	void onMSg(const ExMessage& msg)
	{
		//如果有键盘消息
		if (msg.message == WM_KEYDOWN)
		{
			//改变蛇的移动方向 获取键盘按键 
			//判断是哪个按键,如果是其他按键则不执行操作 
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
	//判断蛇是否吃到了食物
	void snakeEatFood()
	{
		if (snake1.snake_eat(food1))//如果蛇和食物产生了碰撞
		{
			//蛇的长度增加
			snake1.snake_grow();
			//食物重新生成,位置随机
			food1.change_pos();
			//每吃一个食物,得分增加5,最后输出其得分
			score += 5;
		}
	}
private:
	snake snake1;//包含蛇对象和食物对象
	food food1;
};
